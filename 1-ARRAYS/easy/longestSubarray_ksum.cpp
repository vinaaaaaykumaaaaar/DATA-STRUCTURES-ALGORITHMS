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

void brute_force(vector<int> a, int k)
{

    // tc -> O(n^2);
    // sc -> O(1);

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

// prefix sum (hashing)

void better(vector<int> a, int k)
{

    // tc ->  O(n);
    // sp -> O(n);
    unordered_map<int, int> m;

    int mx = 0, sum = 0;

    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];

        if (sum == k)
            mx = max(mx, i + 1);

        int rem = sum - k;

        if (m.find(rem) != m.end())
        {
            mx = max(mx, i - m[rem]);
        }

        m[sum] = i;
    }

    cout << mx << endl;
}

void optimal(vector<int> a, int k)
{

    // tc-> O(n);
    // sc -> O(1);

    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;

    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= a[left++];
        }

        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;

        if (right < a.size())
            sum += a[right];
    }

    cout << maxLen << endl;
}

int main()
{

    vector<int> a = {2, 3, 5};
    vector<int> b = {2, 3, 1, 1, 1, 1, 2, 5, 1, 9};

    vector<vector<int>> test_cases = {a, b};

    cout << "-----------------------------------------------------------------" << endl;

    // Brute force approach test case
    cout << "--------------------- B R U T E - F O R C E ---------------------" << endl;
    brute_force(a, 5);
    brute_force(b, 10);

    // Better approach test case
    cout << "-------------------------- B E T T E R --------------------------" << endl;
    better(a, 5);
    better(b, 10);

    // Optimal approach test case
    cout << "------------------------  O P T I M A L  ------------------------" << endl;
    optimal(a, 5);
    optimal(b, 10);
    cout << "-----------------------------------------------------------------" << endl;

    return 0;
}
