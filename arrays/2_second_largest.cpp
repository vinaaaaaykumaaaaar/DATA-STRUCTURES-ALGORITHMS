/*
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

#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 4, 7, 7, 5};

    int largest = INT_MIN;
    int second_largest = INT_MIN;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > largest)
            second_largest = largest, largest = v[i];
        if (v[i] < largest && v[i] > second_largest)
            second_largest = v[i];
    }

    cout << largest << " " << second_largest << endl;
}