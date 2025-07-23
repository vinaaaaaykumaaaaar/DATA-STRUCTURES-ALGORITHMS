/*
Given an array arr[], sort the array according to the following relations:

arr[i] >= arr[i - 1], if i is even, ∀ 1 <= i < n
arr[i] <= arr[i - 1], if i is odd, ∀ 1 <= i < n
Find the resultant array.[consider 1-based indexing]

Examples:

Input: arr[] = [1, 2, 2, 1]
Output: [1 2 1 2]
 Explanation:
For i = 2, arr[i] >= arr[i-1]. So, 2 >= 1.
For i = 3, arr[i] <= arr[i-1]. So, 1 <= 2.
For i = 4, arr[i] >= arr[i-1]. So, 2 >= 1.

Input: arr[] = [1, 3, 2]
Output: [1 3 2]
Explanation:
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <unordered_map>

using namespace std;

void solve(vector<int> &a)
{

    sort(a.begin(), a.end());

    vector<int> v;
    int l = 0;
    int r = a.size() - 1;

    for (int i = 0; i < a.size(); i++)
    {
        if (!(i & 1))
            v.push_back(a[l++]);
        else
            v.push_back(a[r--]);
    }

    for (auto x : v)
        cout << x << " ";
    cout << endl;
}

void optimal(vector<int> &a)
{

    for (int i = 1; i < a.size(); i++)
    {
        if (i & 1)
        {
            if (a[i] <= a[i - 1])
                swap(a[i], a[i - 1]);
        }
    }

    for (auto x : a)
        cout << x << " ";
    cout << endl;
}

int main()
{

    vector<int> a = {1, 2, 2, 1};
    vector<int> b = {1, 3, 2};

    optimal(a);
    optimal(b);
    return 0;
}