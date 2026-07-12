def insertion_sort(arr):
    """
    Sort a list in ascending order using the insertion sort algorithm.

    Parameters:
        arr (list): The list of comparable elements to sort.

    Returns:
        list: A new sorted list (the original list is not modified).
    """
    sorted_arr = arr[:]
    for i in range(1, len(sorted_arr)):
        key = sorted_arr[i]
        j = i - 1
        while j >= 0 and sorted_arr[j] > key:
            sorted_arr[j + 1] = sorted_arr[j]
            j -= 1
        sorted_arr[j + 1] = key
    return sorted_arr


def main():
    data = [64, 34, 25, 12, 22, 11, 90]
    print("Original list:", data)
    print("Sorted list:  ", insertion_sort(data))


if __name__ == "__main__":
    main()
