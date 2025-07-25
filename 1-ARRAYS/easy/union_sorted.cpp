/*
Problem Statement: Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.

The union of two arrays can be defined as the common and distinct elements in the two arrays.NOTE: Elements in the union should be in ascending order.

Examples

Example 1:
Input:
n = 5,m = 5.
arr1[] = {1,2,3,4,5}
arr2[] = {2,3,4,4,5}
Output:
 {1,2,3,4,5}

Explanation:
Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1
Distnict Elemennts in arr2 are : No distinct elements.
Union of arr1 and arr2 is {1,2,3,4,5}

Example 2:
Input:
n = 10,m = 7.
arr1[] = {1,2,3,4,5,6,7,8,9,10}
arr2[] = {2,3,4,4,5,11,12}
Output: {1,2,3,4,5,6,7,8,9,10,11,12}
Explanation:
Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1,6,7,8,9,10
Distnict Elemennts in arr2 are : 11,12
Union of arr1 and arr2 is {1,2,3,4,5,6,7,8,9,10,11,12}

*/

#include <bits/stdc++.h>

using namespace std;

void brute_force(vector<int> &a, vector<int> &b)
{

    // tc -> O(nlogn + m logm)
    // sc -> n+m -> on worst case where every element is unique;
    set<int> s;
    for (auto x : a)
        s.insert(x); // O(nlogn)

    for (auto x : b)
        s.insert(x); // O(mlogm)

    for (auto x : s)
        cout << x << " ";
    cout << endl;
}

void better(vector<int> &a, vector<int> &b)
{
    // tc -> (nlogn + mlogm)
    // sc -> n+m

    map<int, int> m;
    for (auto x : a)
        m[x]++;
    for (auto x : b)
        m[x]++;

    for (auto x : m)
        cout << x.first << " ";
    cout << endl;
}

void optimal(vector<int> &a, vector<int> &b)
{
    vector<int> v;

    int i = 0, j = 0;

    while (i < a.size() && j < b.size())
    {
        // Add the smaller element (or either if equal)
        if (a[i] <= b[j])
        {
            if (v.empty() || v.back() != a[i])
            {
                v.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (v.empty() || v.back() != b[j])
            {
                v.push_back(b[j]);
            }
            j++;
        }
    }
    // Handle remaining elements from array a
    while (i < a.size())
    {
        if (v.empty() || v.back() != a[i])
        {
            v.push_back(a[i]);
        }
        i++;
    }

    // Handle remaining elements from array b
    while (j < b.size())
    {
        if (v.empty() || v.back() != b[j])
        {
            v.push_back(b[j]);
        }
        j++;
    }

    // Output the result
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{

    vector<int> a = {1, 3, 5, 7, 9, 11};
    vector<int> b = {2, 4, 6, 8, 10};
    vector<int> c = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> d = {2, 3, 4, 4, 5, 11, 12};

    vector<vector<int>>
        test_cases = {a, b, c};

    cout << "-----------------------------------------------------------------" << endl;

    // Brute force approach test case
    cout << "--------------------- B R U T E - F O R C E ---------------------" << endl;
    brute_force(a, b);
    brute_force(c, d);

    // Better approach test case
    cout << "-------------------------- B E T T E R --------------------------" << endl;
    better(a, b);
    better(c, d);

    // Optimal approach test case
    cout << "------------------------  O P T I M A L  ------------------------" << endl;
    optimal(a, b);
    optimal(c, d);

    cout << "-----------------------------------------------------------------" << endl;

    return 0;
}