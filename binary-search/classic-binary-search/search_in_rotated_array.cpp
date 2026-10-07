#include <iostream>
#include <vector>

using namespace std;

int brute_force(vector<int> &arr, int target)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
            return i;
    }

    return -1;
}

long long bianry_search(vector<int> &arr, int target)
{
    long long left = 0, right = arr.size() - 1;

    while (left <= right)
    {
        long long mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        else if (arr[left] <= arr[mid])
        {
            if (arr[left] <= target && arr[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            if (arr[mid] > target && target <= arr[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {3, 4, 5, 6, 7, 0, 1, 2};
    // cout << brute_force(arr, 0) << endl;
    cout << bianry_search(arr, 0) << endl;
    return 0;
}