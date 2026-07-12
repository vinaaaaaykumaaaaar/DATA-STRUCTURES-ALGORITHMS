/*
Union of Two Sorted Arrays

Problem Statement: Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.

The union of two arrays can be defined as the common and distinct elements in the two arrays.

NOTE: Elements in the union should be in ascending order.

Examples

Input:n = 5,m = 5 arr1[] = {1,2,3,4,5}  arr2[] = {2,3,4,4,5}
Output: {1,2,3,4,5}
Explanation: Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1
Distnict Elemennts in arr2 are : No distinct elements.
Union of arr1 and arr2 is {1,2,3,4,5}

Input:n = 10,m = 7,arr1[] = {1,2,3,4,5,6,7,8,9,10}arr2[] = {2,3,4,4,5,11,12}
Output: {1,2,3,4,5,6,7,8,9,10,11,12}
Explanation: Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1,6,7,8,9,10
Distnict Elemennts in arr2 are : 11,12
Union of arr1 and arr2 is {1,2,3,4,5,6,7,8,9,10,11,12}
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> b = {2, 3, 4, 4, 5, 11, 12};
    vector<int> v;

    int i = 0, j = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            if (v.empty() || v.back() != a[i])
            {
                v.push_back(a[i]);
            }
            i++;
        }
        else if (b[j] < a[i])
        {
            if (v.empty() || v.back() != b[j])
            {
                v.push_back(b[j]);
            }
            j++;
        }
        else
        {
            if (v.empty() || v.back() != a[i])
            {
                v.push_back(a[i]);
            }
            i++;
            j++;
        }
    }

    while (i < a.size())
    {
        if (v.empty() || v.back() != a[i])
        {
            v.push_back(a[i]);
        }
        i++;
    }

    while (j < b.size())
    {
        if (v.empty() || v.back() != b[j])
        {
            v.push_back(b[j]);
        }
        j++;
    }

    for (auto x : v)
        cout << x << " ";
    cout << endl;
}