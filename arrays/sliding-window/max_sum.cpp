#include <iostream>
#include <vector>
#include <stdio.h>
#include <limits.h>

using namespace std;

long long maximumSubarraySum(vector<int> &nums, int k)
{
    int n = nums.size();

    vector<int> P(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        P[i + 1] = P[i] + nums[i];
    }

    long long maximum = INT_MIN;

    long long sum = 0;

    for (int i = 0; i <= n - k; i++)
    {
        sum = P[i + k] - P[i];
        maximum = max(maximum, sum);
    }

    return maximum;
}

long long sliding_window(vector<int> &arr, int k)
{
    int n = arr.size();

    long long windowSum = 0;

    long long maxSum = LLONG_MIN;

    // calculate the first window
    for (int i = 0; i < k; i++)
        windowSum += arr[i];

    maxSum = windowSum;

    // start sliding
    for (int i = k; i < n; i++)
    {
        int l = i - k;
        windowSum -= arr[l];
        windowSum += arr[i];

        maxSum = max(windowSum, maxSum);
    }

    return maxSum;
}

int main()
{
    vector<int> arr = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int k = 4;

    // int maximum = 0;

    // for (int i = 0; i <= arr.size() - k; i++) // (n-k)
    // {
    //     int current = 0;

    //     for (int j = i; j < i + k; j++) // (k)
    //     {
    //         current += arr[j];
    //         cout << current << " ";
    //     }
    //     cout << endl;
    //     maximum = max(maximum, current);
    // }

    // // (n-k) * k = nk - k^2
    // cout << endl;
    // cout << maximum << endl;

    // cout << maximumSubarraySum(arr, k) << endl;

    cout << sliding_window(arr, k) << "\n";

    return 0;
}