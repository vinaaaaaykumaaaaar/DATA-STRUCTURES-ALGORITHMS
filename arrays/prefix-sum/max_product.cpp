#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int maxProd = INT_MIN;

        int prefix = 1, suffix = 1;

        for (int i = 0; i < n; ++i)
        {
            if (prefix == 0)
                prefix = 1;
            if (suffix == 0)
                suffix = 1;

            prefix *= nums[i];
            suffix *= nums[n - i - 1];

            maxProd = max(maxProd, max(suffix, prefix));
        }

        return maxProd;
    }
};

int main()
{
    vector<int> nums = {2, 3, -2, 4};

    Solution sol;

    cout << sol.maxProduct(nums) << endl;

    return 0;
}