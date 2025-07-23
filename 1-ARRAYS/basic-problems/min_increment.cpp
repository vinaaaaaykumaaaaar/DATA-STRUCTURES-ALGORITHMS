/*
Given an array of integers where 1≤A[i]≤(10^18). In one operation you can either
Increment/Decrement any element by 1. The task is to find the minimum operations
needed to be performed on the array elements to make all array elements equal.

Examples:

Input : A[] = { 1, 5, 7, 10 }
Output : 11
Increment 1 by 4, 5 by 0.
Decrement 7 by 2, 10 by 5.
New array A = { 5, 5, 5, 5 } with
cost of operations = 4 + 0 + 2 + 5 = 11.
Input : A = { 10, 2, 20 }
Output : 18


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
    int s = 0, e = a.size() - 1;

    int cost = 0;

    int m1 = s + (e - s) / 2;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < a[m1])
            cost += (a[m1] - a[i]);
        else if (a[i] > a[m1])
            cost += (a[i] - a[m1]);
    }

    cout << cost << endl;
}

int main()
{

    vector<int> a = {1, 5, 7, 10};
    vector<int> b = {10, 2, 20};

    cout << "----------------------------" << endl;
    solve(a);
    cout << "----------------------------" << endl;
    solve(b);
    cout << "----------------------------" << endl;

    return 0;
}