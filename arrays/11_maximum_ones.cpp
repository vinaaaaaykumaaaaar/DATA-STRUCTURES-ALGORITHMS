/*
Count Maximum Consecutive One's in the array
Problem Statement: Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array..

Examples
Example 1:
Input: prices = {1, 1, 0, 1, 1, 1}
Output: 3
Explanation: There are two consecutive 1’s and three consecutive 1’s in the array out of which maximum is 3.

Example 2:
Input: prices = {1, 0, 1, 1, 0, 1}
Output: 2
Explanation: There are two consecutive 1's in the array.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {1, 1, 0, 1, 1, 1};

    int maximum = 0;
    int current_maximum = 0;

    for (int i = 0; i < a.size(); i++)
    {
        cout << maximum << " " << current_maximum << endl;
        if (a[i] == 1)
        {
            current_maximum++;
        }
        else
        {

            current_maximum = 0;
        }
        maximum = max(maximum, current_maximum);
    }

    cout << maximum << endl;
}