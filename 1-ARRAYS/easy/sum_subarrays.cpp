/*
Given an integer array arr[], compute the sum of all possible sub-arrays of the array. A sub-array is a contiguous part of the array.

Examples:

Input: arr[] = [1, 4, 5, 3, 2]
Output: 116
Explanation: Sum of all possible subarrays of the array [1, 4, 5, 3, 2] is 116.

Input: arr[] = [1, 2, 3, 4]
Output: 50
Explanation: Sum of all possible subarrays of the array [1, 2, 3, 4] is 50.

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

    int res = 0;

    for (int i = 0; i < a.size(); i++)
    {
        int temp = 0;

        for (int j = i; j < a.size(); j++)
        {
            temp += a[j];
            res += temp;
        }
    }

    cout << res << endl;
}

void optimal(vector<int> &a)
{
    int n = a.size(), res = 0;

    for (int i = 0; i < a.size(); i++)
    {
        res += (a[i] * (1 + i) * (n - i));
    }

    cout << res << endl;
}

int main()
{

    vector<int> a = {1, 4, 5, 3, 2};

    optimal(a);
    return 0;
}