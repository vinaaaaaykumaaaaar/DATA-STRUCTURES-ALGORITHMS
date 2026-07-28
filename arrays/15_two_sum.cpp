/*
Two Sum : Check if a pair with given sum exists in Array

Problem Statement: Given an array of integers arr[] and an integer target.

1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.

2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

Examples

Input: N = 5, arr[] = {2,6,5,8,11}, target = 14
Output : YES
Explanation: arr[1] + arr[3] = 14. So, the answer is “YES” for first variant for second variant output will be : [1,3].

Input: N = 5, arr[] = {2,6,5,8,11}, target = 15
Output : NO.
Explanation: There exist no such two numbers whose sum is equal to the target.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> two_sum(const vector<int> &nums, int target_sum)
{
    int n = nums.size();

    int i = 0, j = n - 1;

    while (i <= j)
    {
        int sum = nums[i] + nums[j];
        if (sum == target_sum)
            return {i, j};
        if (sum > target_sum)
            j--;
        else
            i++;
    }
    return {-1, -1};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {2, 5, 6, 8, 11};
    int target_sum = 14;

    vector<int> result_arr = two_sum(arr, target_sum);

    for (auto x : result_arr)
        cout << x << " ";
    cout << "\n";

    return 0;
}