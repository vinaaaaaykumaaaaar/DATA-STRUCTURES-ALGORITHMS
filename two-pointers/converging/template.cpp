/*
Use when you see...
    - Array is sorted (or you sort it first)
    - Find a pair/triplet with a target sum
    - Palindrome check
    - Maximize/minimize some value using both ends

Avoid when...
    - Array is unsorted and order matters
    - You need more than one pass of information

How to decide which pointer to move:
    - If result is too small → move left pointer right (increase value).
    - If too large → move right pointer left (decrease value).
    - If found → process and move both.

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {};
    int target = 0 ;
    int left = 0 , right = arr.size() - 1 ;

    while (left < right)
    {
        int res = arr[left] + arr[right]; 

        if(res == target)
        {
            left++ , right--;
        }
        else if (res > target)
        {
            right--;
        }
        else 
        {
            left++;
        }
    }
}