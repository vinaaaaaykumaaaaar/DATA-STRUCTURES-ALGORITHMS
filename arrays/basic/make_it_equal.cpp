/*
You are given an array of n-elements, you have to find the number of operations needed to make all elements of array equal. Where a single operation can increment an element by k. If it is not possible to make all elements equal print -1.

Example : 

Input : arr[] = {4, 7, 19, 16},  k = 3
Output : 10

Input : arr[] = {4, 4, 4, 4}, k = 3
Output : 0

Input : arr[] = {4, 2, 6, 8}, k = 3
Output : -1
*/

#include<bits/stdc++.h>

using namespace std;

int minOps(vector<int>& arr, int k) {
  
    int maxVal = *max_element(arr.begin(), arr.end());
    int res = 0;

    for (int x : arr) {
      
        // check if element can be made equal to max
        // if not, return -1
        if ((maxVal - x) % k != 0)
            return -1;

        // else, update res for required operations
        res += (maxVal - x) / k;
    }

    return res;
}

int main()
{
    vector<int> arr = { 21, 33, 9, 45, 63 };
    int k = 6;

    cout << minOps(arr, k);
    return 0;
}