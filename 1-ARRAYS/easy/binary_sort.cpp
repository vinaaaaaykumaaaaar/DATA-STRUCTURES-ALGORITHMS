/*
You are given a binary array arr[], where each element is either 0 or 1. Your task is to rearrange the array in increasing order in place (without using extra space). You do not need to return anything; simply modify the input array.

Examples:

Input: arr[] = [1, 0, 1, 1, 0]
Output: [0, 0, 1, 1, 1]
Explanation: After arranging the elements in increasing order, elements will be as 0 0 1 1 1.
Input: arr[] = [1, 0, 1, 1, 1, 1, 1, 0, 0, 0]
Output: [0, 0, 0, 0, 1, 1, 1, 1, 1, 1]
Explanation: After arranging the elements in increasing order, elements will be 0 0 0 0 1 1 1 1 1 1.
Input: arr[] = [1, 1, 1, 1]
Output: [1, 1, 1, 1]
Explanation: Since the array already contains only 1s, no change is needed.
Constraints:
1 ≤ arr.size() ≤ 106
arr[i] ∈ {0,1} for all valid indices i.

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)


*/

#include <bits/stdc++.h>

using namespace std;

void brute_force(vector<int> a)
{

    // tc->O(nlogn)
    // sc-> O(1)
    sort(a.begin(), a.end());

    for (auto x : a)
        cout << x << " ";
    cout << endl;
}

void better(vector<int> a)
{

    // tc -> O(n);
    // sc -> O(1)
    unordered_map<int, int> m;
    for (auto x : a)
        m[x]++;

    int c0 = m[0], c1 = m[1];

    for (int i = 0; i < c0; i++)
        a[i] = 0;
    for (int i = c0; i < c0 + c1; i++)
        a[i] = 1;

    for (auto x : a)
        cout << x << " ";
    cout << endl;
}

void optimal(vector<int> a)
{

    // tc -> O(n)
    // sc-> O(1)

    int l = 0, r = a.size() - 1;

    while (l < r)
    {
        if (a[l] == 0)
            l++;
        if (a[r] == 1)
            r--;
        if (a[l] == 1 && a[r] == 0)
        {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }

    for (auto x : a)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{

    vector<int> a = {1, 0, 1, 1, 0};
    vector<int> b = {1, 0, 1, 1, 1, 1, 1, 0, 0, 0};
    vector<int> c = {1, 1, 1, 1};

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