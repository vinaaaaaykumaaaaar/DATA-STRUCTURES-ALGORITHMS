/*
Linear Search in C

Problem Statement: Given an array, and an element num the task is to find if num is present in the given array or not. If present print the index of the element or print -1.

Example 1:
Input:
 arr[] = 1 2 3 4 5, num = 3
Output:
 2  `
Explanation:
 3 is present at the 2nd index of the array.

Example 2:
Input:
 arr[] = 5 4 3 2 1, num = 5
Output:
 0
Explanation:
 5 is present at the 0th index of the array.
*/

#include <bits/stdc++.h>
using namespace std;

int linear_search(vector<int> &v, int key)
{
    if (v.empty())
        return -1;

    for (int i = 0; i < v.size(); i++)
        if (v[i] == key)
            return i;

    return -1;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    int key = 3;

    int index = linear_search(v, key);

    if (index != -1)
        cout << v[index] << endl;
    else
        cout << "not found" << endl;

    return 0;
}