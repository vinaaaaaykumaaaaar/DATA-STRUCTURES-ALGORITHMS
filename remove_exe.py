import os
import sys

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


def main():
    """Main function to run the script."""
    # Get the root folder from command line argument or current directory
    if len(sys.argv) > 1:
        root_folder = sys.argv[1]
    else:
        # Use the directory where the script is located
        root_folder = os.path.dirname(os.path.abspath(__file__))
        print(f"No folder specified. Using script directory: {root_folder}")
    
    # Ask for confirmation before deleting
    print(f"\nThis will delete ALL .exe files in: {root_folder}")
    print("This includes all subfolders within this directory.")
    confirmation = input("Are you sure you want to continue? (yes/no): ").strip().lower()
    
    if confirmation in ['yes', 'y']:
        delete_exe_files(root_folder)
    else:
        print("Operation cancelled.")


if __name__ == "__main__":
    main()