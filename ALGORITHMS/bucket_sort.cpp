#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * BUCKET SORT ALGORITHM
 *
 * What is Bucket Sort?
 * Bucket sort is a sorting algorithm that works by distributing elements into
 * several buckets, sorting each bucket individually, and then combining them back.
 *
 * How it works:
 * 1. Create empty buckets (usually same number as input elements)
 * 2. Distribute elements into buckets based on their value
 * 3. Sort each bucket individually (often using insertion sort)
 * 4. Concatenate all sorted buckets to get final result
 *
 * Time Complexity:
 * - Best/Average case: O(n + k) where n = elements, k = buckets
 * - Worst case: O(n²) when all elements go to same bucket
 *
 * Space Complexity: O(n + k)
 *
 * Best for: Uniformly distributed data in a known range
 */

void bucketSort(vector<float> &arr)
{
    int n = arr.size();

    // Step 1: Create empty buckets
    // We create 'n' buckets to distribute elements
    vector<vector<float>> buckets(n);

    cout << "Step 1: Created " << n << " empty buckets\n";

    // Step 2: Put array elements in different buckets
    // For values between 0 and 1, we multiply by n to get bucket index
    for (int i = 0; i < n; i++)
    {
        // Calculate bucket index
        // For element 0.78 with n=5: bucket_index = 0.78 * 5 = 3.9 → 3
        int bucket_index = n * arr[i];

        // Handle edge case: if arr[i] equals 1.0, it would go to bucket n
        // which doesn't exist, so we put it in the last bucket
        if (bucket_index >= n)
        {
            bucket_index = n - 1;
        }

        buckets[bucket_index].push_back(arr[i]);

        cout << "Element " << arr[i] << " goes to bucket " << bucket_index << "\n";
    }

    // Step 3: Sort individual buckets
    // We use C++ STL sort (which is typically introsort - hybrid of quicksort, heapsort, and insertion sort)
    cout << "\nStep 3: Sorting each bucket individually:\n";
    for (int i = 0; i < n; i++)
    {
        if (!buckets[i].empty())
        {
            sort(buckets[i].begin(), buckets[i].end());

            cout << "Bucket " << i << " after sorting: ";
            for (float val : buckets[i])
            {
                cout << val << " ";
            }
            cout << "\n";
        }
    }

    // Step 4: Concatenate all buckets back into original array
    cout << "\nStep 4: Combining all buckets:\n";
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        // Copy all elements from bucket i to original array
        for (float val : buckets[i])
        {
            arr[index] = val;
            index++;
        }
    }

    cout << "Final sorted array: ";
    for (float val : arr)
    {
        cout << val << " ";
    }
    cout << "\n";
}

// Alternative implementation for integer arrays in a specific range
void bucketSortInt(vector<int> &arr, int min_val, int max_val)
{
    int n = arr.size();
    int range = max_val - min_val + 1;

    // Create buckets for the range
    vector<vector<int>> buckets(range);

    cout << "\nInteger Bucket Sort for range [" << min_val << ", " << max_val << "]:\n";

    // Distribute elements into buckets
    for (int i = 0; i < n; i++)
    {
        int bucket_index = arr[i] - min_val; // Normalize to 0-based index
        buckets[bucket_index].push_back(arr[i]);
        cout << "Element " << arr[i] << " goes to bucket " << bucket_index << "\n";
    }

    // Sort each bucket and concatenate
    int index = 0;
    for (int i = 0; i < range; i++)
    {
        if (!buckets[i].empty())
        {
            sort(buckets[i].begin(), buckets[i].end());
            for (int val : buckets[i])
            {
                arr[index] = val;
                index++;
            }
        }
    }

    cout << "Sorted integer array: ";
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << "\n";
}

int main()
{
    cout << "=== BUCKET SORT DEMONSTRATION ===\n\n";

    // Example 1: Floating point numbers between 0 and 1
    cout << "Example 1: Sorting floating point numbers (0.0 to 1.0)\n";
    cout << "----------------------------------------\n";

    vector<float> float_arr = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};

    cout << "Original array: ";
    for (float val : float_arr)
    {
        cout << val << " ";
    }
    cout << "\n\n";

    bucketSort(float_arr);

    cout << "\n"
         << string(50, '=') << "\n\n";

    // // Example 2: Integer numbers in a specific range
    // cout << "Example 2: Sorting integers in range [10, 50]\n";
    // cout << "----------------------------------------\n";

    // vector<int> int_arr = {42, 15, 28, 33, 19, 47, 12, 35, 21, 38};

    // cout << "Original array: ";
    // for (int val : int_arr)
    // {
    //     cout << val << " ";
    // }
    // cout << "\n\n";

    // bucketSortInt(int_arr, 10, 50);

    cout << "\n=== KEY POINTS FOR BEGINNERS ===\n";
    cout << "1. Bucket sort works best when data is uniformly distributed\n";
    cout << "2. Number of buckets affects performance - too few or too many can be inefficient\n";
    cout << "3. Good for sorting floating point numbers in known ranges\n";
    cout << "4. Not suitable for data with unknown or very large ranges\n";
    cout << "5. Can be stable (maintains relative order of equal elements)\n";

    return 0;
}