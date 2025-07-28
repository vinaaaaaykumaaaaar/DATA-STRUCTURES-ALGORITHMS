/*
Implement Upper Bound

Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the upper bound of x.

Pre-requisite: Binary Search algorithm

Examples

Example 1:
Input Format: N = 4, arr[] = {1,2,2,3}, x = 2
Result: 3
Explanation: Index 3 is the smallest index such that arr[3] > x.

Example 2:
Input Format: N = 6, arr[] = {3,5,8,9,15,19}, x = 9
Result: 4
Explanation: Index 4 is the smallest index such that arr[4] > x.

*/

#include <bits/stdc++.h>
using namespace std;

int upper_bound(vector<int> &a, int t)
{
    int high = a.size(), low = 0;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (a[mid] > t)
            ans = mid, high = mid - 1;
        else
            low = mid + 1;
    }

    return ans;
}

int main()
{
    vector<int> a = {1, 2, 2, 3};
    vector<int> b = {3, 5, 8, 9, 15, 19};

    cout << upper_bound(a, 2) << endl;
    cout << upper_bound(b, 9) << endl;

    return 0;
}