/*
Longest Subarray with given Sum K(Positives)

Problem Statement: Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.

Examples
Example 1:
Input:
 nums = [10, 5, 2, 7, 1, 9], k = 15
Output:
 4
Explanation:
 The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. Therefore, the length of this sub-array is 4.

Example 2:
Input:
 nums = [-3, 2, 1], k = 6
Output:
 0
Explanation:
 There is no sub-array in the array that sums to 6. Therefore, the output is 0.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {10, 5, 2, 7, 1, 9};
    int k = 15;
    int n = v.size();
    int maximum = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + v[j];
            if (sum == k)
            {
                maximum = max(maximum, j - i + 1);
            }
            // only if all numbers are positive
            else if (sum > k)
            {
                break;
            }
        }
    }

    cout << maximum << endl; // 4
}