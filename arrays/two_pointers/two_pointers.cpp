/*
Given an array arr[] of n integers and a target value, find the number of pairs of integers in the array whose sum is equal to target.

Examples:

Input: arr[] = [1, 5, 7, -1, 5], target = 6
Output:  3
Explanation: Pairs with sum 6 are (1, 5), (7, -1) & (1, 5).

Input: arr[] = [1, 1, 1, 1], target = 2
Output:  6
Explanation: Pairs with sum 2 are (1, 1), (1, 1), (1, 1), (1, 1), (1, 1) and (1, 1).

Input: arr[] = [10, 12, 10, 15, -1], target = 125
Output:  0
Explanation: There is no pair with sum = target
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> a = {1, 5, 7, -1, 5};
    int target = 6;
    int n = a.size();

    vector<vector<int>> res;

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        {
            int sum = a[i] + a[j];
            if (sum == target)
                res.push_back({a[i], a[j]});
        }
    }

    for (auto x : res)
    {
        for (auto y : x)
            cout << y << " ";
        cout << ",";
    }
}