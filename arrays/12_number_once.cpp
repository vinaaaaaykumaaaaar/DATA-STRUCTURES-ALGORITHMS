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

int main()
{
    vector<int> a = {1, 2, 1, 2, 3, 4, 3};

    map<int, int> hash;

    for (auto x : a)
        hash[x]++;

    for (auto x : hash)
        if (x.second == 1)
            cout << x.first << endl;
}