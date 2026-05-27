/*
Write a function to count the number of triplets in an integer array nums that could form the sides of a triangle.

For three sides to form a valid triangle, all three of these conditions must hold: (a + b > c), (a + c > b), and (b + c > a), where (a), (b), and (c) are the side lengths. In other words, the sum of every possible pair must exceed the third side.

The triplets do not need to be unique.

Example:

Input:

nums = [11,4,9,6,15,18]

Output:

10

Explanation: Valid combinations are...

4, 15, 18
6, 15, 18
9, 15, 18
11, 15, 18
9, 11, 18
6, 11, 15
9, 11, 15
4, 6, 9

*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int triangleNumber(vector<int> nums)
    {
        int count = 0;

        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (nums[i] + nums[j] > nums[k])
                        count++;
                }
            }
        }

        return count;
    }

    int triangleNumberOptimize(vector<int> nums)
    {
        int count = 0;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = n - 1; i >= 2; --i)
        {
            int left = 0, right = i - 1;

            while (left < right)
            {
                if (nums[left] + nums[right] > nums[i])
                {
                    count += right - left;
                    right--;
                }

                else
                    left++;
            }
        }
        return count;
    }
};

int main()
{
    vector<int> nums = {11, 4, 9, 6, 15, 18};

    Solution sol;

    cout << sol.triangleNumberOptimize(nums) << endl;
}