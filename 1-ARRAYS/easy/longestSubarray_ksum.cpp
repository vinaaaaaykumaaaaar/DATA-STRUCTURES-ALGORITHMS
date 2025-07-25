/*
Longest Subarray with given Sum K(Positives)

Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.

Examples

Example 1:
Input Format: N = 3, k = 5, array[] = {2,3,5}
Result: 2
Explanation: The longest subarray with sum 5 is {2, 3}. And its length is 2.

Example 2:
Input Format: N = 5, k = 10, array[] = {2,3,5,1,9}
Result: 3
Explanation: The longest subarray with sum 10 is {2, 3, 5}. And its length is 3.
*/

#include <bits/stdc++.h>

using namespace std;

void brute_force(vector<int> &a, int k)
{

    int m = 0;

    for (int i = 0; i < a.size(); i++)
    {
        int sum = 0;
        int count = 0;
        for (int j = i; j < a.size(); j++)
        {
            sum += a[j];
            ++count;
            if (sum == k)
            {
                m = max(m, count);
                break;
            }
        }
    }

    cout << m << endl;
}

void better(vector<int> &a)
{
}

void optimal(vector<int> &a)
{
}

int main()
{

    vector<int> a = {2, 3, 5};
    vector<int> b = {2, 3, 5, 1, 9};

    vector<vector<int>> test_cases = {a, b};

    cout << "-----------------------------------------------------------------" << endl;

    // Brute force approach test case
    cout << "--------------------- B R U T E - F O R C E ---------------------" << endl;
    brute_force(a, 5);
    brute_force(b, 10);

    // Better approach test case
    cout << "-------------------------- B E T T E R --------------------------" << endl;
    for (auto test_case : test_cases)
    {
        better(test_case);
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