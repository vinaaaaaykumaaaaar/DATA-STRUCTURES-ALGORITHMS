/*
Given an unsorted array arr[] of size n, containing elements from the range 1 to n,
 it is known that one number in this range is missing, and another number occurs twice in the array,
 find both the duplicate number and the missing number.

Examples:

Input: arr[] = [3, 1, 3]
Output: [3, 2]
Explanation: 3 is occurs twice and 2 is missing.

Input: arr[] = [4, 3, 6, 2, 1, 1]
Output: [1, 5]
Explanation: 1 is occurs twice and 5 is missing.
*/

#include <bits/stdc++.h>

using namespace std;

void brute_force(vector<int> &a)
{

    // tc -> O(n);
    // sc -> O(n);
    vector<int> v(a.size() + 1, 0);

    for (int i = 0; i < a.size(); i++)
    {
        v[a[i]] += 1;
    }

    int r = 0, m = 0;

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] == 2)
            r = i;
        else if (v[i] == 0)
            m = i;
    }

    cout << "missing = " << m << " repeating = " << r << endl;
}

int main()
{

    vector<int> a = {3, 1, 3};
    vector<int> b = {4, 3, 6, 2, 1, 1};
    vector<int> c = {1, 2, 4, 5, 5};

    vector<vector<int>> test_cases = {a, b, c};

    cout << "-----------------------------------------------------------------" << endl;

    // Brute force approach test case
    cout << "--------------------- B R U T E - F O R C E ---------------------" << endl;
    for (auto test_case : test_cases)
    {
        brute_force(test_case);
    }

    cout << "-----------------------------------------------------------------" << endl;

    return 0;
}