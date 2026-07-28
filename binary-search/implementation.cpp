#include <bits/stdc++.h>

using namespace std;

int binary_search(const vector<int> &nums, int target_element)
{
    int n = nums.size();
    int left = 0, right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target_element)
            return mid;
        if (nums[mid] > target_element)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target_element = 7;

    cout << binary_search(arr, target_element) << "\n";

    return 0;
}