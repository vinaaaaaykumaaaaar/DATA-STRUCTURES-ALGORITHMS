/*
Find all subsequences with sum equals to K
Given an array arr[] of length n and a number k, the task is to find all the
subsequences of the array with sum of its elements equal to k.

Note: A subsequence is a subset that can be derived from an array by removing
zero or more elements, without changing the order of the remaining elements.

Examples:

Input: arr[] = [1, 2, 3], k = 3
Output: [ [1, 2], [3] ]
Explanation: All the subsequences of the given array are:
[ [1], [1, 2], [1, 2, 3], [1, 3], [2], [2, 3], [3], [] ]
Out of which only two subsequences have sum of their elements equal to 3.

Input: arr[] = [1, 2, 3], k = 7
Output: []
Explanation: Sum of all the elements of the array is 6, which is smaller than the
required sum, thus they are no subsequences with sum of its elements equal to 7.

Input: arr[] = [17, 18, 6, 11, 2, 4], k = 6
Output: [ [2, 4], [6] ]


*/

#include <bits/stdc++.h>
using namespace std;

// Recursive function to generate all
// subsequences with sum of elements k
void findSubsequence(int ind, int sum, int k, vector<int> &cur,
                     vector<int> &arr, vector<vector<int>> &res)
{
    int n = arr.size();

    // base case
    if (ind == n)
    {

        // check if sum of elements of current
        // subset is equal to k
        if (sum == k)
        {

            // add the subset in result
            res.push_back(cur);
        }
        return;
    }

    // skip the current element arr[ind]
    findSubsequence(ind + 1, sum, k, cur, arr, res);

    // add the current element in subset
    cur.push_back(arr[ind]);
    findSubsequence(ind + 1, sum + arr[ind], k, cur, arr, res);

    // remove the added element
    cur.pop_back();
}

// Function to find the subsequences
// with sum of its elements k
vector<vector<int>> subsequencesSumK(vector<int> &arr, int k)
{

    // to store the subsequences
    // with sum of its elements k
    vector<vector<int>> res;

    // to store the current subset
    vector<int> cur;

    findSubsequence(0, 0, k, cur, arr, res);

    return res;
}

int main()
{
    vector<int> arr = {17, 18, 6, 11, 2, 4};
    int k = 6;
    vector<vector<int>> ans = subsequencesSumK(arr, k);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}