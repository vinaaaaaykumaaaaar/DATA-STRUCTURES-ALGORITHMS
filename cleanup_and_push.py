import os
import sys
import subprocess


def run_git(args, root):
    """Run a git command in `root` and return the CompletedProcess."""
    return subprocess.run(['git'] + args, cwd=root, capture_output=True, text=True)


def is_build_file(path):
    """True for compiled artifacts we never want to commit (.exe, a.out)."""
    name = os.path.basename(path)
    return name.lower().endswith('.exe') or name == 'a.out'


def list_changes(root):
    """Return a list of (status, path) tuples from `git status --porcelain`."""
    result = run_git(['status', '--porcelain'], root)
    if result.returncode != 0:
        print(f"Error reading git status: {result.stderr.strip()}")
        return None

    changes = []
    for line in result.stdout.splitlines():
        if not line.strip():
            continue
        status = line[:2]
        rest = line[3:]
        # Renames/copies are shown as "old -> new"; keep the new path.
        if ' -> ' in rest:
            rest = rest.split(' -> ', 1)[1]
        path = rest.strip().strip('"')
        changes.append((status, path))
    return changes


def print_changes(changes, title):
    print("\n" + "=" * 60)
    print(title)
    print("=" * 60)
    if not changes:
        print("  (no changes)")
        return
    for status, path in changes:
        marker = "   <-- build file" if is_build_file(path) else ""
        print(f"  {status}  {path}{marker}")
    print(f"\n  Total: {len(changes)} change(s)")


def delete_build_files(root):
    """
    Delete all .exe / a.out files on disk (scans the whole tree, skipping .git).

    Untracked build files simply disappear; tracked ones become a pending
    deletion that the per-file commit step will record in the repo.
    """
    print("\n" + "=" * 60)
    print("Removing build files (.exe, a.out)")
    print("=" * 60)

    deleted = []
    for dirpath, dirnames, filenames in os.walk(root):
        if '.git' in dirnames:
            dirnames.remove('.git')  # never descend into the git internals
        for filename in filenames:
            if filename.lower().endswith('.exe') or filename == 'a.out':
                file_path = os.path.join(dirpath, filename)
                try:
                    os.remove(file_path)
                    deleted.append(file_path)
                    print(f"  deleted: {os.path.relpath(file_path, root)}")
                except FileNotFoundError:
                    pass
                except PermissionError:
                    print(f"  permission denied: {file_path}")
                except Exception as e:
                    print(f"  error deleting {file_path}: {e}")

    if not deleted:
        print("  (none found)")
    print(f"\n  Removed {len(deleted)} build file(s)")
    return deleted


def commit_message_for(status, path):
    """Pick a meaningful commit message based on the change type."""
    s = status.strip()
    if 'R' in s:
        return f"rename: {path}"
    if 'D' in s:
        return f"remove: {path}"
    return f"solved: {path}"


def commit_and_push_each(root, changes):
    """Stage, commit, and push every change individually."""
    pushed = 0
    failed = []

    for status, path in changes:
        print("\n" + "-" * 60)
        print(f"Processing [{status}] {path}")

        # Stage just this path (-A captures adds, edits, and deletions).
        add = run_git(['add', '-A', '--', path], root)
        if add.returncode != 0:
            print(f"  stage failed: {add.stderr.strip()}")
            failed.append(path)
            continue

        message = commit_message_for(status, path)
        commit = run_git(['commit', '-m', message], root)
        if commit.returncode != 0:
            combined = commit.stdout + commit.stderr
            if 'nothing to commit' in combined:
                print("  nothing to commit (skipped)")
            else:
                print(f"  commit failed: {commit.stderr.strip()}")
                failed.append(path)
            continue
        print(f"  committed: {message}")

        push = run_git(['push'], root)
        if push.returncode != 0:
            print(f"  push failed: {push.stderr.strip()}")
            failed.append(path)
            continue
        print("  pushed")
        pushed += 1

    return pushed, failed


def main():
    """Cleanup compiled files, then commit + push each change individually."""
    if len(sys.argv) > 1:
        root = os.path.abspath(sys.argv[1])
    else:
        root = os.path.dirname(os.path.abspath(__file__))
        print(f"No folder specified. Using script directory: {root}")

    if not os.path.isdir(root):
        print(f"Error: '{root}' is not a directory.")
        sys.exit(1)

    check = run_git(['rev-parse', '--is-inside-work-tree'], root)
    if check.returncode != 0:
        print(f"Error: '{root}' is not a git repository.")
        sys.exit(1)

    # 1) List all current changes (build files are flagged).
    changes = list_changes(root)
    if changes is None:
        sys.exit(1)
    print_changes(changes, "Step 1: All current changes")

    if not changes:
        print("\nWorking tree is clean. Nothing to do.")
        return

    # 2 & 3) Detect and remove build files.
    delete_build_files(root)

    # 4) Re-list the changes after cleanup.
    changes = list_changes(root)
    if changes is None:
        sys.exit(1)
    print_changes(changes, "Step 2: Changes after build-file cleanup")

    if not changes:
        print("\nNo changes left to commit after cleanup.")
        return

    # 5) Add / commit / push each file individually.
    print("\n" + "=" * 60)
    print("Step 3: Commit & push each file individually")
    print("=" * 60)
    pushed, failed = commit_and_push_each(root, changes)

    print("\n" + "=" * 60)
    print(f"Done. {pushed} file(s) committed and pushed.")
    if failed:
        print(f"{len(failed)} file(s) had issues:")
        for f in failed:
            print(f"  - {f}")
    print("=" * 60)


if __name__ == "__main__":
    main()
