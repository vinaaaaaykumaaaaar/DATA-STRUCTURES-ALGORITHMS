/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.



Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]


Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{

    vector<int> a = {2, 0, 2, 1, 1, 0};
    unordered_map<int, int> m;

    for (int i = 0; i < a.size(); i++)
    {
        m[a[i]]++;
    }

    vector<int> res;
    for (int i = 0; i < m[0]; i++)
        res.push_back(0);
    for (int i = 0; i < m[1]; i++)
        res.push_back(1);
    for (int i = 0; i < m[2]; i++)
        res.push_back(2);

    for (auto x : res)
        cout << x << " ";
}