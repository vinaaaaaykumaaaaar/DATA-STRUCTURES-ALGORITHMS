/*
Given an integer array arr[] and an integer k, determine whether there exist two indices i and j
such that arr[i] == arr[j] and |i - j| ≤ k. If such a pair exists, return 'Yes', otherwise return 'No'.

Examples:

Input: k = 3, arr[] = [1, 2, 3, 4, 1, 2, 3, 4]
Output: No
Explanation: Each element in the given array arr[] appears twice and the distance between every element and its duplicate is 4.

Input: k = 3, arr[] = [1, 2, 3, 1, 4, 5]
Output: Yes
Explanation: 1 is present at index 0 and 3.

Input: k = 3, arr[] = [1, 2, 3, 4, 5]
Output: No
Explanation: There is no duplicate element in arr[].
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
#include <unordered_set>

using namespace std;

bool solve(vector<int> &a, int k)
{

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        {
            if ((a[i] == a[j]) && (abs(i - j) <= k))
                return true;
        }
    }

    return false;
}

bool optimal(vector<int> &a, int k)
{
    unordered_set<int> s;
    for (int i = 0; i < a.size(); i++)
    {
        if (s.find(a[i]) != s.end())
            return true;

        s.insert(a[i]);

        if (i >= k)
            s.erase(a[i - k]);
    }

    return false;
}

int main()
{

    vector<int> a = {1, 2, 3, 4, 1, 2, 3, 4};
    vector<int> b = {1, 2, 3, 1, 4, 5};
    vector<int> c = {1, 2, 3, 4, 5};

    cout << abs(1 - 10) << endl;

    cout << optimal(a, 3) << endl;
    cout << optimal(b, 3) << endl;
    cout << optimal(c, 3) << endl;

    return 0;
}
