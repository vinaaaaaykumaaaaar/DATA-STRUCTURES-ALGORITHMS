/*
Move all Zeros to the end of the array

Problem Statement: You are given an array of integers, your task is to move all the zeros in the array to the end of the array and move non-negative integers to the front by maintaining their order.

Examples
Input: 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1
Output: 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0
Explanation: All the zeros are moved to the end and non-negative integers are moved to front by maintaining order
Input : 1,2,0,1,0,4,0
Output: 1,2,1,4,0,0,0
Explanation : All the zeros are moved to the end and non-negative integers are moved to front by maintaining order
*/

#include <bits/stdc++.h>
using namespace std;

void move_zeros(vector<int> &v)
{
    int j = 0;
    int count = v.size();
    for (int i = 0; i < count; i++)
    {
        if (v[i] != 0)
            swap(v[i], v[j++]);
    }
}

int main()
{
    vector<int> v = {1, 0, 2, 3, 0, 4, 0, 1};
    move_zeros(v);

    for (auto x : v)
        cout << x << " ";
    cout << endl;
}