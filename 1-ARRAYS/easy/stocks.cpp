/*
Stock Buy And Sell

Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Examples
Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and
sell on day 5 (price = 6), profit = 6-1 = 5.

Note: That buying on day 2 and selling on day 1
is not allowed because you must buy before
you sell.

Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are
done and the max profit = 0.

*/

#include <bits/stdc++.h>

using namespace std;

void brute_force(vector<int> a)
{

    // tc-> O(n^2);
    // sc-> O(1);

    int p = INT_MIN;

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i; j < a.size(); j++)
        {
            if (a[j] >= a[i])
            {
                p = max(p, a[j] - a[i]);
            }
        }
    }

    cout << p << endl;
}

void better(vector<int> a)
{

    int mp = 0;
    int n = a.size();
    int minp = INT_MAX;

    // tc->O(n);
    // sc->O(1);

    for (int i = 0; i < a.size(); i++)
    {
        minp = min(a[i], minp);
        mp = max(mp, a[i] - minp);
    }

    cout << mp << endl;
}

int main()
{

    vector<int> a = {7, 1, 5, 3, 6, 4};
    vector<int> b = {7, 6, 4, 3, 1};

    vector<vector<int>> test_cases = {a, b};

    cout << "-----------------------------------------------------------------" << endl;

    // Brute force approach test case
    cout << "--------------------- B R U T E - F O R C E ---------------------" << endl;
    for (auto test_case : test_cases)
    {
        brute_force(test_case);
    }

    // Better approach test case
    cout << "-------------------------- B E T T E R --------------------------" << endl;
    for (auto test_case : test_cases)
    {
        better(test_case);
    }

    cout << "-----------------------------------------------------------------" << endl;

    return 0;
}