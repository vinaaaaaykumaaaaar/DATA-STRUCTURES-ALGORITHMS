/*
Remove Duplicates in-place from Sorted Array

Problem Statement: Given an integer array sorted in non-decreasing order, remove the duplicates in place such that each unique element appears only once. The relative order of the elements should be kept the same.

If there are k elements after removing the duplicates, then the first k elements of the array should hold the final result. It does not matter what you leave beyond the first k elements.

Input: arr[]=[1,1,2,2,2,3,3]
Output: [1,2,3,_,_,_,_]
Explanation: Total number of unique elements are 3, i.e[1,2,3] and Therefore return 3 after assigning [1,2,3] in the beginning of the array.
Input: arr[]=[1,1,1,2,2,3,3,3,3,4,4]
Output: [1,2,3,4,_,_,_,_,_,_,_]
Explanation: Total number of unique elements are 4, i.e[1,2,3,4] and Therefore return 4 after assigning [1,2,3,4] in the beginning of the array.
*/

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &v)
{
    if (v.empty())
        return 0;

    int j = 0;
    for (size_t i = 1; i < v.size() - 1; i++)
    {
        if (v[j] != v[i] && j != i && j != i + 1)
        {
            swap(v[++j], v[i]);
        }
    }

    return j + 1;
}

int main()
{
    vector<int> v = {1, 1, 2, 2, 2, 3, 3};

    int size = removeDuplicates(v);

    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }

    cout << endl;
}
