/*
Find the number that appears once, and the other numbers twice


Problem Statement: Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

Examples

Example 1:
Input Format: arr[] = {2,2,1}
Result: 1
Explanation: In this array, only the element 1 appear once and so it is the answer.

Example 2:
Input Format: arr[] = {4,1,2,1,2}
Result: 4
Explanation: In this array, only element 4 appear once and the other elements appear twice. So, 4 is the answer.

*/

#include <bits/stdc++.h>

using namespace std;

void brute_force(vector<int> a)
{

    // tc ->O(nlogn)
    // sc -> O(1)
    sort(a.begin(), a.end());
    int ans = -1;

    for (int i = 0; i < a.size(); i += 2)
    {
        if (a[i] != a[i + 1])
        {
            ans = a[i];
            break;
        }
    }

    cout << ans << endl;
}

void better(vector<int> a)
{

    // tc-> O(nlogn)
    // sc -> O(m) m is the size of map = n/2 + 1 = O(n);

    unordered_map<int, int> m;
    for (auto x : a)
        m[x]++;

    for (auto x : m)
        if (x.second == 1)
        {
            cout << x.first << endl;
            break;
        }
}

void optimal(vector<int> a)
{

    // tc -> O(n);
    // sc -> O(1);
    int xr = 0;
    for (auto x : a)
        xr = xr ^ x;

    cout << xr << endl;
}

int main()
{

    vector<int> a = {2, 2, 1};
    vector<int> b = {4, 1, 2, 1, 2};
    vector<int> c = {1, 2, 3, 4, 5, 4, 3, 2, 1};

    vector<vector<int>> test_cases = {a, b, c};

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

    // Optimal approach test case
    cout << "------------------------  O P T I M A L  ------------------------" << endl;
    for (auto test_case : test_cases)
    {
        optimal(test_case);
    }

    cout << "-----------------------------------------------------------------" << endl;

    return 0;
}