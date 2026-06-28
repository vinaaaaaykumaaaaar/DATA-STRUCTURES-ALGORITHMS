/*
Example 1:
Input: N = 5, array[] = {1,2,3,4,5}
Output: True.
Explanation: The given array is sorted i.e Every element in the array is smaller than or equals to its next values, So the answer is True.

Example 2:
Input: N = 5, array[] = {5,4,6,7,8}
Output: False.
Explanation: The given array is Not sorted i.e Every element in the array is not smaller than or equal to its next values, So the answer is False.
Here element 5 is not smaller than or equal to its future elements.
*/

#include <bits/stdc++.h>
using namespace std;

bool isSorted(const vector<int> &v)
{
    for (size_t i = 0; i + 1 < v.size(); i++)
        if (v[i] > v[i + 1])
            return false;

    return true;
}

int main()
{
    std::vector<int> v = {5, 4, 6, 7, 8};
    std::cout << std::boolalpha << isSorted(v) << '\n';
}