/*
Given an array of integers arr[], the task is to move all the zeros to the end of the array while maintaining the relative order of all non-zero elements.

Examples:

Input: arr[] = [1, 2, 0, 4, 3, 0, 5, 0]
Output: arr[] = [1, 2, 4, 3, 5, 0, 0, 0]
Explanation: There are three 0s that are moved to the end.

Input: arr[] = [10, 20, 30]
Output: arr[] = [10, 20, 30]
Explanation: No change in array as there are no 0s.

Input: arr[] = [0, 0]
Output: arr[] = [0, 0]
Explanation: No change in array as there are all 0s.

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

    int c = 0;

    for (auto x : a)
        if (x == 0)
            c++;

    vector<int> v;

    // tc -> O(n)
    // sc -> O(n)

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != 0)
        {
            v.push_back(a[i]);
        }
    }

    while (c)
        v.push_back(0), c--;

    a = v;
    for (auto x : a)
        cout << x << " ";
    cout << endl;
}

void optimal(vector<int> &a)
{

    int j = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != 0)
        {
            if (i != j)
                swap(a[i], a[j]);
            j++;
        }
    }

    for (auto x : a)
        cout << x << " ";
    cout << endl;
}

int main()
{

    vector<int> a = {1, 2, 0, 4, 3, 0, 5, 0};
    vector<int> b = {10, 20, 30};
    vector<int> c = {0, 0};
    vector<int> d = {0};

    cout << "----------------------------------" << endl;
    optimal(a);
    cout << "----------------------------------" << endl;
    optimal(b);
    cout << "----------------------------------" << endl;
    optimal(c);
    cout << "----------------------------------" << endl;
    optimal(d);
    cout << "----------------------------------" << endl;

    return 0;
}
