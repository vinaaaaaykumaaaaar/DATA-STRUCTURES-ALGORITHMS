/*
Two Sum : Check if a pair with given sum exists in Array

Problem Statement: Given an array of integers arr[] and an integer target.

1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.

2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

Note: You are not allowed to use the same element twice. Example: If the target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.

Examples:

Example 1:
Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 14
Result: YES (for 1st variant)
       [1, 3] (for 2nd variant)
Explanation: arr[1] + arr[3] = 14. So, the answer is “YES” for the first variant and [1, 3] for 2nd variant.

Example 2:
Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 15
Result: NO (for 1st variant)
    [-1, -1] (for 2nd variant)
Explanation: There exist no such two numbers whose sum is equal to the target.

*/

#include <bits/stdc++.h>

using namespace std;

void brute_force(vector<int> a, int t)
{

    int ith = -1, jth = -1;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i; j < a.size(); j++)
        {
            if (a[i] + a[j] == t)
            {
                ith = i, jth = j;
            }
        }
    }

    cout << ith << " " << jth << endl;
}

void optimal_solution(vector<int> a, int t)
{
    int l = 0, r = a.size() - 1;
    while (l <= r)
    {
        if (l == r)
        {
            l = -1, r = -1;
            break;
        }
        if (a[l] + a[r] == t)
        {
            break;
        }
        if (a[l] + a[r] > t)
            r--;
        else
            l++;
    }

    cout << l << " " << r << endl;
}

int main()
{
    vector<int> a = {2, 6, 5, 8, 11};
    vector<int> b = {2, 6, 5, 8, 11};

    brute_force(a, 14);
    brute_force(b, 15);

    optimal_solution(a, 14);
    optimal_solution(b, 15);
}