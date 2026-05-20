/*
Given an input integer array nums, write a function to find all unique triplets [nums[i], nums[j], nums[k]] such that i, j, and k are distinct indices, and the sum of nums[i], nums[j], and nums[k] equals zero. Ensure that the resulting list does not contain any duplicate triplets.

Input:

nums = [-1,0,1,2,-1,-1]
Output:

[[-1,-1,2],[-1,0,1]]

Explanation: Both nums[0], nums[1], nums[2] and nums[1], nums[2], nums[4] both include [-1, 0, 1] and sum to 0. nums[0], nums[3], nums[4] ([-1,-1,2]) also sum to 0.

Since we are looking for unique triplets, we can ignore the duplicate [-1, 0, 1] triplet and return [[-1, -1, 2], [-1, 0, 1]].

The order of the triplets and the order of the elements within the triplets do not matter.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> nums)
    {
        vector<vector<int>> uni;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        uni.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }

        return uni;
    }
};

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -1};

    Solution sol;
    vector<vector<int>> res = sol.threeSum(nums);

    for (auto r : res)
    {
        for (auto x : r)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}