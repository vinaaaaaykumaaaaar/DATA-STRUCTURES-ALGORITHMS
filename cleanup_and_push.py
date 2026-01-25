import os
import sys
import subprocess

def delete_exe_files(root_folder):
    """
    Delete all .exe files in the root folder and all its subfolders.
    
    Args:
        root_folder (str): Path to the root folder
    
    Returns:
        tuple: (count of deleted files, list of deleted file paths)
    """
    # Verify the root folder exists
    if not os.path.exists(root_folder):
        print(f"Error: The folder '{root_folder}' does not exist.")
        return 0, []
    
    if not os.path.isdir(root_folder):
        print(f"Error: '{root_folder}' is not a directory.")
        return 0, []
    
    # Convert to absolute path for safety
    root_folder = os.path.abspath(root_folder)
    
    deleted_files = []
    deleted_count = 0
    
    print(f"Scanning folder: {root_folder}")
    print("-" * 60)
    
    # Walk through all directories and subdirectories
    for dirpath, dirnames, filenames in os.walk(root_folder):
        for filename in filenames:
            # Check if file has .exe extension (case-insensitive)
            if filename.lower().endswith('.exe'):
                file_path = os.path.join(dirpath, filename)
                
                # Double-check the file is within the root folder
                if os.path.abspath(file_path).startswith(root_folder):
                    try:
                        os.remove(file_path)
                        deleted_files.append(file_path)
                        deleted_count += 1
                        print(f"Deleted: {file_path}")
                    except PermissionError:
                        print(f"Permission denied: {file_path}")
                    except Exception as e:
                        print(f"Error deleting {file_path}: {e}")
    
    print("-" * 60)
    print(f"Total .exe files deleted: {deleted_count}")
    
    return deleted_count, deleted_files


def run_git_commands(root_folder, commit_message="solved"):
    """
    Run git commands to add, commit, and push changes.
    
    Args:
        root_folder (str): Path to the git repository
        commit_message (str): Commit message to use
    """
    try:
        # Change to the repository directory
        os.chdir(root_folder)
        
        print("\n" + "=" * 60)
        print("Running Git Commands")
        print("=" * 60)
        
        # Git add
        print("\n[1/3] Running: git add .")
        result = subprocess.run(['git', 'add', '.'], capture_output=True, text=True)
        if result.returncode != 0:
            print(f"Error: {result.stderr}")
            return False
        print("✓ Files staged successfully")
        
        # Git commit
        print(f"\n[2/3] Running: git commit -m \"{commit_message}\"")
        result = subprocess.run(['git', 'commit', '-m', commit_message], capture_output=True, text=True)
        if result.returncode != 0:
            # Check if there's nothing to commit
            if "nothing to commit" in result.stdout or "nothing to commit" in result.stderr:
                print("✓ No changes to commit")
            else:
                print(f"Error: {result.stderr}")
                return False
        else:
            print("✓ Changes committed successfully")
            print(result.stdout.strip())
        
        # Git push
        print("\n[3/3] Running: git push")
        result = subprocess.run(['git', 'push'], capture_output=True, text=True)
        if result.returncode != 0:
            print(f"Error: {result.stderr}")
            return False
        print("✓ Changes pushed successfully")
        print(result.stdout.strip())
        
        print("\n" + "=" * 60)
        print("All Git operations completed successfully!")
        print("=" * 60)
        return True
        
    except FileNotFoundError:
        print("Error: Git is not installed or not in PATH")
        return False
    except Exception as e:
        print(f"Error running git commands: {e}")
        return False


def main():
    """Main function to run the script."""
    # Get the root folder from command line argument or current directory
    if len(sys.argv) > 1:
        root_folder = sys.argv[1]
    else:
        # Use the directory where the script is located
        root_folder = os.path.dirname(os.path.abspath(__file__))
        print(f"No folder specified. Using script directory: {root_folder}")
    
    # Delete .exe files (no confirmation needed for automated workflow)
    deleted_count, deleted_files = delete_exe_files(root_folder)
    
    if deleted_count > 0:
        print(f"\n✓ Cleaned up {deleted_count} .exe file(s)")
    else:
        print("\n✓ No .exe files found")
    
    # Run git commands
    run_git_commands(root_folder)


if __name__ == "__main__":
    main()