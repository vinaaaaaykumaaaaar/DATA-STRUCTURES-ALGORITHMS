/*
Leaders in an array

Given an array arr[] of size n, the task is to find all the Leaders in the array. An element is a Leader if it is greater than or equal to all the elements to its right side.

Note: The rightmost element is always a leader.

Examples:

Input: arr[] = [16, 17, 4, 3, 5, 2]
Output: [17 5 2]
Explanation: 17 is greater than all the elements to its right i.e., [4, 3, 5, 2], therefore 17 is a leader. 5 is greater than all the elements to its right i.e., [2], therefore 5 is a leader. 2 has no element to its right, therefore 2 is a leader.

Input: arr[] = [1, 2, 3, 4, 5, 2]
Output: [5 2]
Explanation: 5 is greater than all the elements to its right i.e., [2], therefore 5 is a leader. 2 has no element to its right, therefore 2 is a leader.
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void optimal(vector<int> &arr)
{
    vector<int> result;

    int max = arr[arr.size() - 1];

    result.push_back(max);

    for (int i = arr.size() - 2; i >= 0; i--)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            result.push_back(max);
        }
    }

    reverse(result.begin(), result.end());

    for (auto x : result)
        cout << x << " ";
    cout << "\n";
}

int main()
{
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> result;

    for (int i = 0; i < arr.size(); i++)
    {
        int j;
        for (j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] > arr[i])
                break;
        }

        if (j == arr.size())
            result.push_back(arr[i]);
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    cout << endl;

    optimal(arr);

    return 0;
}