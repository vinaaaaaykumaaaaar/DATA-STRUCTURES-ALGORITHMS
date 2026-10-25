#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();

        int maxSum = INT_MIN;
        int curSum = nums[0];

        for (int i = 1; i < n; i++)
        {
            curSum = max(nums[i], curSum + nums[i]);
            maxSum = max(maxSum, curSum);
        }

        return maxSum;
    }
};

int main()
{
    vector<int> a = {5, 4, -1, 7, 8};
    Solution s;
    cout << s.maxSubArray(a) << endl;
    return 0;
}