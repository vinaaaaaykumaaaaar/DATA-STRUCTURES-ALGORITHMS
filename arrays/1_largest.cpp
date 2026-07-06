/*
Find the Largest element in an array

Problem Statement: Given an array, we have to find the largest element in the array.

Examples
Example 1:
Input:
 arr[] = {2, 5, 1, 3, 0}
Output:
 5
Explanation:

5 is the largest element in the array.

Example 2:
Input:
 arr[] = {8, 10, 5, 7, 9}
Output:
 10
Explanation:

10 is the largest element in the array.


*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {2, 5, 1, 3, 0};

    sort(v.begin(), v.end());

    cout << v[v.size() - 1] << endl;

    return 0;
}
