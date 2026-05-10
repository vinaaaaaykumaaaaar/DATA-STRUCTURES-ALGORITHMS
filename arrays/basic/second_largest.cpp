/*
Find Second Smallest and Second Largest Element in an array

Problem Statement: Given an array, find the second smallest and second largest element in the array. Print ‘-1’ in the event that either of them doesn’t exist.

Example 1:
Input:
 [1, 2, 4, 7, 7, 5]
Output:

Second Smallest : 2
Second Largest : 5
Explanation:
  The elements are sorted as 1, 2, 4, 5, 7, 7.
Hence, the second smallest element is 2, and the second largest element is 5.

Example 2:
Input:
 [1]
Output:

Second Smallest : -1
Second Largest : -1
Explanation:
  Since there is only one element in the array, it is both the largest and smallest element.
Therefore, there is no second smallest or second largest element present.
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {1, 2, 4, 7, 7, 5};

    int first = -1, second = -1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (first < arr[i])
        {
            second = first;
            first = arr[i];
        }
        else if (second < arr[i] && first != arr[i])
        {
            second = arr[i];
        }
    }

    cout << "Second Largest Element = " << second << endl;
}