"""Stage, commit, and push working-tree changes.

Build artifacts (.exe, a.out) are wiped from disk first so they never enter
history. All file deletions (including any tracked build artifacts) are then
grouped into a single commit, while every other change is committed and pushed
individually. Anything under editor or git-internal directories is skipped.
"""

from __future__ import annotations

import os
import subprocess
import sys
from pathlib import Path
from typing import NamedTuple


# --- Constants ---------------------------------------------------------------

IGNORED_DIRS: frozenset[str] = frozenset({
    '.vscode', '.claude', '.git', '__pycache__', '.idea',
})

BUILD_FILENAMES: frozenset[str] = frozenset({'a.out'})
BUILD_SUFFIXES: tuple[str, ...] = ('.exe',)

# Map porcelain status code -> commit-message prefix. First match wins.
COMMIT_PREFIXES: tuple[tuple[str, str], ...] = (
    ('R', 'rename'),
    ('D', 'remove'),
)
DEFAULT_PREFIX = 'solved'

SEPARATOR = '=' * 60
SUBSEPARATOR = '-' * 60


# --- Types -------------------------------------------------------------------

class Change(NamedTuple):
    status: str
    path: str


# --- Git ---------------------------------------------------------------------

def run_git(args: list[str], root: Path) -> subprocess.CompletedProcess[str]:
    """Run a git command in `root` and return the CompletedProcess."""
    return subprocess.run(
        ['git', *args],
        cwd=root,
        capture_output=True,
        text=True,
    )


# --- Path predicates ---------------------------------------------------------

def is_ignored(path: str) -> bool:
    """True if any component of `path` lives in an ignored directory."""
    parts = path.replace('\\', '/').split('/')
    return not IGNORED_DIRS.isdisjoint(parts)


def is_build_file(name: str) -> bool:
    """True for compiled artifacts that should never be committed."""
    return name in BUILD_FILENAMES or name.lower().endswith(BUILD_SUFFIXES)


# --- Status parsing ----------------------------------------------------------

def list_changes(root: Path) -> list[Change] | None:
    """Return non-ignored entries from `git status --porcelain`, or None on error."""
    result = run_git(['status', '--porcelain'], root)
    if result.returncode != 0:
        print(f"Error reading git status: {result.stderr.strip()}")
        return None

    changes: list[Change] = []
    for line in result.stdout.splitlines():
        if not line.strip():
            continue
        # Porcelain line: "XY <path>"  or  "XY <old> -> <new>"
        status, rest = line[:2], line[3:]
        if ' -> ' in rest:
            rest = rest.partition(' -> ')[2]
        path = rest.strip().strip('"')
        if not is_ignored(path):
            changes.append(Change(status, path))
    return changes


# --- Reporting ---------------------------------------------------------------

def print_section(title: str) -> None:
    print(f"\n{SEPARATOR}\n{title}\n{SEPARATOR}")


def print_changes(changes: list[Change], title: str) -> None:
    print_section(title)
    if not changes:
        print("  (no changes)")
        return
    for status, path in changes:
        marker = "   <-- build file" if is_build_file(os.path.basename(path)) else ""
        print(f"  {status}  {path}{marker}")
    print(f"\n  Total: {len(changes)} change(s)")


def list_and_report(root: Path, title: str) -> list[Change] | None:
    """List current changes and print them under `title`. None on git error."""
    changes = list_changes(root)
    if changes is not None:
        print_changes(changes, title)
    return changes


# --- File cleanup ------------------------------------------------------------

def delete_build_files(root: Path) -> int:
    """Remove every .exe / a.out under `root`, skipping ignored directories."""
    print_section("Removing build files (.exe, a.out)")

    deleted = 0
    for dirpath, dirnames, filenames in os.walk(root):
        # Prune ignored dirs in place so os.walk doesn't descend into them.
        dirnames[:] = [d for d in dirnames if d not in IGNORED_DIRS]
        for filename in filenames:
            if not is_build_file(filename):
                continue
            file_path = Path(dirpath, filename)
            try:
                file_path.unlink()
            except FileNotFoundError:
                continue
            except PermissionError:
                print(f"  permission denied: {file_path}")
                continue
            except OSError as exc:
                print(f"  error deleting {file_path}: {exc}")
                continue
            deleted += 1
            print(f"  deleted: {file_path.relative_to(root)}")

    print(f"\n  Removed {deleted} build file(s)" if deleted else "  (none found)")
    return deleted


# --- Commit pipeline ---------------------------------------------------------

def commit_message_for(change: Change) -> str:
    """Pick a commit message from the porcelain status code."""
    for code, prefix in COMMIT_PREFIXES:
        if code in change.status:
            return f"{prefix}: {change.path}"
    return f"{DEFAULT_PREFIX}: {change.path}"


def commit_deletions_together(
    root: Path, deletions: list[Change]
) -> tuple[int, list[str]]:
    """Stage every deletion and commit them as one, then push.

    Returns (files_pushed, failed_paths). All `D`-status paths (tracked file
    removals, including any committed build artifacts) land in a single commit.
    """
    if not deletions:
        return 0, []

    print(f"\n{SUBSEPARATOR}\nGrouping {len(deletions)} deletion(s) into one commit")

    staged: list[str] = []
    failed: list[str] = []
    for change in deletions:
        # -A captures the deletion for this exact path.
        add = run_git(['add', '-A', '--', change.path], root)
        if add.returncode != 0:
            print(f"  stage failed: {change.path}: {add.stderr.strip()}")
            failed.append(change.path)
        else:
            staged.append(change.path)
            print(f"  staged: {change.path}")

    if not staged:
        print("  nothing staged; skipping commit")
        return 0, failed

    summary = f"remove: {len(staged)} deleted file(s) and build artifacts"
    body = "\n".join(f"- {path}" for path in staged)
    commit = run_git(['commit', '-m', summary, '-m', body], root)
    if commit.returncode != 0:
        if 'nothing to commit' in (commit.stdout + commit.stderr):
            print("  nothing to commit (skipped)")
            return 0, failed
        print(f"  commit failed: {commit.stderr.strip()}")
        return 0, failed + staged
    print(f"  committed: {summary}")

    push = run_git(['push'], root)
    if push.returncode != 0:
        print(f"  push failed: {push.stderr.strip()}")
        return 0, failed + staged
    print("  pushed")
    return len(staged), failed


def commit_and_push_each(root: Path, changes: list[Change]) -> tuple[int, list[str]]:
    """Stage, commit, and push every change individually."""
    pushed = 0
    failed: list[str] = []

    for change in changes:
        print(f"\n{SUBSEPARATOR}\nProcessing [{change.status}] {change.path}")

        # -A captures adds, edits, and deletions for this exact path.
        add = run_git(['add', '-A', '--', change.path], root)
        if add.returncode != 0:
            print(f"  stage failed: {add.stderr.strip()}")
            failed.append(change.path)
            continue

        message = commit_message_for(change)
        commit = run_git(['commit', '-m', message], root)
        if commit.returncode != 0:
            if 'nothing to commit' in (commit.stdout + commit.stderr):
                print("  nothing to commit (skipped)")
            else:
                print(f"  commit failed: {commit.stderr.strip()}")
                failed.append(change.path)
            continue
        print(f"  committed: {message}")

        push = run_git(['push'], root)
        if push.returncode != 0:
            print(f"  push failed: {push.stderr.strip()}")
            failed.append(change.path)
            continue
        print("  pushed")
        pushed += 1

    return pushed, failed


# --- Entry point -------------------------------------------------------------

def resolve_root(argv: list[str]) -> Path:
    """Resolve the repo root from CLI args, falling back to the script directory."""
    if len(argv) > 1:
        return Path(argv[1]).resolve()
    root = Path(__file__).resolve().parent
    print(f"No folder specified. Using script directory: {root}")
    return root


def print_summary(pushed: int, failed: list[str]) -> None:
    print(f"\n{SEPARATOR}\nDone. {pushed} file(s) committed and pushed.")
    if failed:
        print(f"{len(failed)} file(s) had issues:")
        for path in failed:
            print(f"  - {path}")
    print(SEPARATOR)


def main() -> int:
    root = resolve_root(sys.argv)

    if not root.is_dir():
        print(f"Error: '{root}' is not a directory.")
        return 1

    if run_git(['rev-parse', '--is-inside-work-tree'], root).returncode != 0:
        print(f"Error: '{root}' is not a git repository.")
        return 1

    # 1) Snapshot current changes.
    changes = list_and_report(root, "Step 1: All current changes")
    if changes is None:
        return 1
    if not changes:
        print("\nWorking tree is clean. Nothing to do.")
        return 0

    # 2) Delete build artifacts from disk.
    delete_build_files(root)

    # 3) Re-list after cleanup (deletions surface as new pending changes).
    changes = list_and_report(root, "Step 2: Changes after build-file cleanup")
    if changes is None:
        return 1
    if not changes:
        print("\nNo changes left to commit after cleanup.")
        return 0

    # 4) Group all deletions into a single commit; commit the rest one by one.
    deletions = [c for c in changes if 'D' in c.status]
    others = [c for c in changes if 'D' not in c.status]

    print_section("Step 3: Commit & push all deleted files together")
    del_pushed, del_failed = commit_deletions_together(root, deletions)

    print_section("Step 4: Commit & push each remaining file individually")
    ind_pushed, ind_failed = commit_and_push_each(root, others)

    print_summary(del_pushed + ind_pushed, del_failed + ind_failed)
    return 0


if __name__ == "__main__":
    sys.exit(main())
