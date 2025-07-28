/*
Given an integer array arr[], find the subarray (containing at least one element) which has the maximum possible sum, and return that sum.
Note: A subarray is a continuous part of an array.

Examples:

Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
Output: 11
Explanation: The subarray [7, -1, 2, 3] has the largest sum 11.

Input: arr[] = [-2, -4]
Output: -2
Explanation: The subarray [-2] has the largest sum -2.

Input: arr[] = [5, 4, 1, 7, 8]
Output: 25
Explanation: The subarray [5, 4, 1, 7, 8] has the largest sum 25.
*/

#include <bits/stdc++.h>

using namespace std;

void brute_force(vector<int> &a)
{
    int sum = a[0];

    for (int i = 0; i < a.size(); i++)
    {
        int partial_sum = 0;

        for (int j = i; j < a.size(); j++)
        {
            partial_sum += a[j];
            sum = max(sum, partial_sum);
        }
    }

    cout << sum << endl;
}

void optimal(vector<int> &a)
{
    
}

int main()
{

    vector<int> a = {2, 3, -8, 7, -1, 2, 3};
    vector<int> b = {-2, -4};
    vector<int> c = {5, 4, 1, 7, 8};

    vector<vector<int>> test_cases = {a, b, c};

    cout << "-----------------------------------------------------------------" << endl;

    // Brute force approach test case
    cout << "--------------------- B R U T E - F O R C E ---------------------" << endl;
    for (auto test_case : test_cases)
    {
        brute_force(test_case);
    }

    // Optimal approach test case
    cout << "------------------------  O P T I M A L  ------------------------" << endl;
    for (auto test_case : test_cases)
    {
        optimal(test_case);
    }

    cout << "-----------------------------------------------------------------" << endl;

    return 0;
}