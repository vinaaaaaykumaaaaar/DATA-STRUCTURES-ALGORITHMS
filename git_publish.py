#!/usr/bin/env python3
"""Clean, commit, and push this repository one file at a time.

The cleanup rule is intentionally strict: keep only .cc, .cpp, .txt, and .md
files, plus this script. Every other file below the repository root is removed,
while Git's own metadata is never touched. For safety, the script stops if it
finds a nested Git repository or a linked directory.

Warning: untracked files removed by this script cannot be restored by Git.
Run ``python git_publish.py --dry-run`` to preview the work first.
"""

from __future__ import annotations

import argparse
import os
import stat
import subprocess
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Sequence


KEPT_EXTENSIONS = frozenset({".cc", ".cpp", ".txt", ".md"})


class PublishError(RuntimeError):
    """Raised when the repository cannot be published safely."""


@dataclass(frozen=True)
class Change:
    """One logical Git change; a rename can contain two paths."""

    status: str
    primary_path: str
    paths: tuple[str, ...]


def log(message: str) -> None:
    """Print progress immediately, even when stdout is redirected."""

    print(message, flush=True)


def run_git(
    repo_root: Path,
    arguments: Sequence[str],
    *,
    check: bool = True,
    show_output: bool = False,
) -> subprocess.CompletedProcess[str]:
    """Run Git with literal path handling and captured, UTF-8 output."""

    environment = os.environ.copy()
    environment["GIT_LITERAL_PATHSPECS"] = "1"

    result = subprocess.run(
        ["git", *arguments],
        cwd=repo_root,
        env=environment,
        text=True,
        encoding="utf-8",
        capture_output=True,
        check=False,
    )

    if show_output:
        if result.stdout:
            print(result.stdout, end="", flush=True)
        if result.stderr:
            print(result.stderr, end="", file=sys.stderr, flush=True)

    if check and result.returncode != 0:
        details = (result.stderr or result.stdout).strip()
        command = "git " + " ".join(arguments)
        message = f"Git command failed ({command})."
        if details:
            message += f"\n{details}"
        raise PublishError(message)

    return result


def find_repo_root(start_directory: Path) -> Path:
    """Return the root of the Git repository containing the script."""

    result = subprocess.run(
        ["git", "rev-parse", "--show-toplevel"],
        cwd=start_directory,
        text=True,
        encoding="utf-8",
        capture_output=True,
        check=False,
    )
    if result.returncode != 0:
        raise PublishError("Store this script inside a non-bare Git repository.")
    return Path(result.stdout.strip()).resolve()


def git_path(repo_root: Path, name: str) -> Path:
    """Resolve a path inside Git's metadata directory."""

    raw_path = run_git(repo_root, ["rev-parse", "--git-path", name]).stdout.strip()
    path = Path(raw_path)
    return path if path.is_absolute() else repo_root / path


def validate_repo_state(repo_root: Path) -> str:
    """Reject repository states in which automatic commits would be unsafe."""

    operation_markers = {
        "MERGE_HEAD": "merge",
        "CHERRY_PICK_HEAD": "cherry-pick",
        "REVERT_HEAD": "revert",
        "rebase-merge": "rebase",
        "rebase-apply": "rebase",
        "sequencer": "sequenced Git operation",
    }
    for marker, operation in operation_markers.items():
        if git_path(repo_root, marker).exists():
            raise PublishError(
                f"A {operation} is in progress. Finish or abort it before running this script."
            )

    conflicts = run_git(
        repo_root,
        ["diff", "--name-only", "--diff-filter=U", "-z"],
    ).stdout
    if conflicts:
        raise PublishError("Resolve all merge conflicts before running this script.")

    # Fail before cleanup if a later commit would lack identity information.
    run_git(repo_root, ["var", "GIT_AUTHOR_IDENT"])
    run_git(repo_root, ["var", "GIT_COMMITTER_IDENT"])

    gitlinks = [
        entry
        for entry in run_git(repo_root, ["ls-files", "--stage", "-z"]).stdout.split("\0")
        if entry.startswith("160000 ")
    ]
    if gitlinks:
        raise PublishError(
            "Submodules are not supported because their contents belong to another "
            "repository. Publish or remove them separately first."
        )

    branch_result = run_git(
        repo_root,
        ["symbolic-ref", "--quiet", "--short", "HEAD"],
        check=False,
    )
    if branch_result.returncode != 0:
        raise PublishError("HEAD is detached. Check out a branch before running this script.")
    return branch_result.stdout.strip()


def build_push_arguments(repo_root: Path, branch: str) -> list[str]:
    """Choose a normal push, or establish upstream on the only sensible remote."""

    tracking = run_git(
        repo_root,
        [
            "for-each-ref",
            "--format=%(upstream:remotename)%00%(upstream:remoteref)",
            f"refs/heads/{branch}",
        ],
    ).stdout.rstrip("\r\n")
    if "\0" in tracking:
        upstream_remote, upstream_ref = tracking.split("\0", 1)
        if upstream_remote and upstream_ref:
            # Be independent of push.default and differing local/remote names.
            return ["push", upstream_remote, f"HEAD:{upstream_ref}"]

    remotes = [
        remote
        for remote in run_git(repo_root, ["remote"]).stdout.splitlines()
        if remote
    ]
    if "origin" in remotes:
        remote = "origin"
    elif len(remotes) == 1:
        remote = remotes[0]
    elif not remotes:
        raise PublishError("No Git remote is configured, so there is nowhere to push.")
    else:
        raise PublishError(
            "This branch has no upstream and there are multiple remotes. "
            "Configure an upstream before running this script."
        )

    return ["push", "--set-upstream", remote, branch]


def relative_path(path: Path, repo_root: Path) -> str:
    """Return a Git-style, repository-relative path."""

    return path.relative_to(repo_root).as_posix()


def find_unwanted_files(repo_root: Path, script_path: Path) -> list[Path]:
    """Find files rejected by the strict extension allowlist."""

    try:
        script_relative = script_path.relative_to(repo_root)
    except ValueError as error:
        raise PublishError(
            "The automation script must be stored inside this repository."
        ) from error

    unwanted: list[Path] = []

    def walk_error(error: OSError) -> None:
        location = error.filename or str(repo_root)
        raise PublishError(f"Could not inspect {location}: {error}") from error

    for current, directory_names, file_names in os.walk(
        repo_root,
        topdown=True,
        onerror=walk_error,
        followlinks=False,
    ):
        current_path = Path(current)

        kept_directories: list[str] = []
        for directory_name in directory_names:
            directory = current_path / directory_name

            # Never enter Git metadata or follow a path outside this repository.
            if directory_name.casefold() == ".git":
                continue
            try:
                attributes = getattr(directory.lstat(), "st_file_attributes", 0)
            except OSError as error:
                raise PublishError(f"Could not inspect {directory}: {error}") from error
            reparse_flag = getattr(stat, "FILE_ATTRIBUTE_REPARSE_POINT", 0x0400)
            is_reparse_directory = bool(attributes & reparse_flag)
            if directory.is_symlink() or is_reparse_directory:
                raise PublishError(
                    f"Directory links are not supported: {relative_path(directory, repo_root)}"
                )
            if (directory / ".git").exists():
                raise PublishError(
                    f"Nested Git repositories are not supported: "
                    f"{relative_path(directory, repo_root)}"
                )
            kept_directories.append(directory_name)
        directory_names[:] = kept_directories

        for file_name in file_names:
            path = current_path / file_name
            path_relative = path.relative_to(repo_root)

            # In a linked worktree, .git is a file rather than a directory.
            if path_relative.parts and path_relative.parts[0].casefold() == ".git":
                continue
            if path_relative == script_relative:
                continue
            if path.suffix.lower() in KEPT_EXTENSIONS:
                continue
            unwanted.append(path)

    return sorted(unwanted, key=lambda path: relative_path(path, repo_root).casefold())


def parse_changes(porcelain_output: str) -> list[Change]:
    """Parse NUL-delimited porcelain-v1 output, including rename pairs."""

    records = porcelain_output.split("\0")
    changes: list[Change] = []
    index = 0

    while index < len(records):
        record = records[index]
        index += 1
        if not record:
            continue
        if len(record) < 4 or record[2] != " ":
            raise PublishError("Git returned an unexpected status record.")

        status = record[:2]
        primary_path = record[3:]
        paths = [primary_path]

        if "R" in status or "C" in status:
            if index >= len(records) or not records[index]:
                raise PublishError("Git returned an incomplete rename/copy status record.")
            paths.append(records[index])
            index += 1

        changes.append(Change(status, primary_path, tuple(paths)))

    return sorted(changes, key=lambda change: change.primary_path.casefold())


def get_changes(repo_root: Path) -> list[Change]:
    """Return every tracked and untracked file change in deterministic order."""

    output = run_git(
        repo_root,
        ["status", "--porcelain=v1", "-z", "--untracked-files=all", "--renames"],
    ).stdout
    return parse_changes(output)


def clean_subject_path(path: str) -> str:
    """Keep unusual filenames from creating a multiline commit subject."""

    return path.replace("\r", " ").replace("\n", " ")


def commit_message(change: Change) -> str:
    """Build a concise commit subject that remains clear for duplicate basenames."""

    path = clean_subject_path(change.primary_path)
    action = "removed" if "D" in change.status else "solved"
    return f"{path}: {action}"


def commit_change(repo_root: Path, change: Change) -> bool:
    """Stage one logical change and return whether it produced a commit."""

    run_git(repo_root, ["add", "-A", "--", *change.paths])

    staged_difference = run_git(
        repo_root,
        ["diff", "--cached", "--quiet", "--", *change.paths],
        check=False,
    )
    if staged_difference.returncode == 0:
        remaining_paths = {
            path
            for remaining_change in get_changes(repo_root)
            for path in remaining_change.paths
        }
        if set(change.paths).intersection(remaining_paths):
            raise PublishError(
                f"{change.primary_path} is reported as changed but cannot be staged. "
                "Check for a dirty nested repository."
            )
        log(f"[skip] {change.primary_path} has no net change")
        return False
    if staged_difference.returncode != 1:
        raise PublishError(f"Could not inspect the staged change for {change.primary_path}.")

    message = commit_message(change)
    log(f"[commit] {message}")
    run_git(
        repo_root,
        ["commit", "--only", "--message", message, "--", *change.paths],
        show_output=True,
    )
    return True


def remove_file(path: Path) -> None:
    """Remove a file, including a read-only Windows artifact."""

    try:
        path.unlink()
        return
    except PermissionError:
        try:
            path.chmod(path.stat().st_mode | stat.S_IWRITE)
            path.unlink()
            return
        except OSError as error:
            raise PublishError(f"Could not remove {path}: {error}") from error
    except OSError as error:
        raise PublishError(f"Could not remove {path}: {error}") from error


def preview(repo_root: Path, unwanted_files: Sequence[Path]) -> None:
    """Print cleanup and commit work without changing the repository."""

    if unwanted_files:
        for path in unwanted_files:
            log(f"[dry-run] remove {relative_path(path, repo_root)}")
    else:
        log("[dry-run] no files would be removed")

    unwanted_paths = {
        relative_path(path, repo_root)
        for path in unwanted_files
    }
    tracked_paths = set(
        filter(None, run_git(repo_root, ["ls-files", "-z"]).stdout.split("\0"))
    )

    changes = [
        change
        for change in get_changes(repo_root)
        if not unwanted_paths.intersection(change.paths)
    ]
    changes.extend(
        Change("D ", path, (path,))
        for path in unwanted_paths.intersection(tracked_paths)
    )
    changes.sort(key=lambda change: change.primary_path.casefold())
    if changes:
        for change in changes:
            log(f"[dry-run] commit {commit_message(change)}")
    else:
        log("[dry-run] no current Git changes to commit")

    log("[dry-run] no files, commits, or remotes were changed")


def parse_arguments() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Delete non-source artifacts, create one commit per changed file, "
            "and push the current branch."
        )
    )
    parser.add_argument(
        "--dry-run",
        action="store_true",
        help="show what would happen without deleting, committing, or pushing",
    )
    parser.add_argument(
        "--no-push",
        action="store_true",
        help="perform cleanup and commits locally, but do not push",
    )
    return parser.parse_args()


def main() -> int:
    args = parse_arguments()
    script_path = Path(__file__).resolve()
    repo_root = find_repo_root(script_path.parent)
    branch = validate_repo_state(repo_root)

    # Validate the push destination before deleting files or creating commits.
    push_arguments: list[str] | None = None
    if not args.dry_run and not args.no_push:
        push_arguments = build_push_arguments(repo_root, branch)

    unwanted_files = find_unwanted_files(repo_root, script_path)
    if args.dry_run:
        preview(repo_root, unwanted_files)
        return 0

    committed_count = 0
    while True:
        # Rescan so artifacts created by formatters, hooks, or watchers are removed too.
        for path in find_unwanted_files(repo_root, script_path):
            log(f"[remove] {relative_path(path, repo_root)}")
            remove_file(path)

        changes = get_changes(repo_root)
        if not changes:
            break

        change = changes[0]
        if commit_change(repo_root, change):
            committed_count += 1

    if committed_count:
        noun = "commit" if committed_count == 1 else "commits"
        log(f"[done] created {committed_count} standalone {noun}")
    else:
        log("[done] no changes to commit")

    if args.no_push:
        log("[done] push skipped (--no-push)")
    else:
        log(f"[push] {branch}")
        assert push_arguments is not None
        run_git(repo_root, push_arguments, show_output=True)
        log("[done] push completed")

    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except PublishError as error:
        print(f"[error] {error}", file=sys.stderr)
        raise SystemExit(1)
    except KeyboardInterrupt:
        print("\n[error] cancelled", file=sys.stderr)
        raise SystemExit(130)
