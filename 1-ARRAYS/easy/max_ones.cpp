/*
Count Maximum Consecutive One's in the array

Problem Statement: Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.

Examples:

Example 1:

Input: prices = {1, 1, 0, 1, 1, 1}

Output: 3

Explanation: There are two consecutive 1’s and three consecutive 1’s in the array out of which maximum is 3.

Input: prices = {1, 0, 1, 1, 0, 1}

Output: 2

Explanation: There are two consecutive 1's in the array.
*/

#include <bits/stdc++.h>

using namespace std;

void brute_force(vector<int> &a)
{

    int count = 0, m = -1;

    for (auto i = 0; i < a.size(); i++)
    {
        if (a[i] == 1)
        {
            if (i == a.size() - 1)
                m = max(++count, m);
            else
                count++;
        }

        else
        {
            m = max(m, count);
            count = 0;
        }
    }

    cout << m << endl;
}

int main()
{

    vector<int> a = {1, 1, 0, 1, 1, 1};
    vector<int> b = {1, 0, 1, 1, 0, 1};
    vector<int> c = {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1};

    vector<vector<int>> test_cases = {a, b, c};

    cout << "-----------------------------------------------------------------" << endl;

    // Brute force approach test case
    cout << "--------------------- B R U T E - F O R C E ---------------------" << endl;
    for (auto test_case : test_cases)
    {
        brute_force(test_case);
    }

    cout << "-----------------------------------------------------------------" << endl;

    return 0;
}