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

        for (int i = 0; i < n; ++i)
        {
            int curProd = 1;
            for (int j = i; j < n; ++j)
            {
                curProd *= nums[j];
                maxProd = max(curProd, maxProd);
            }
        }

        return maxProd;
    }
};

int main()
{
    vector<int> nums = {-2, 0, -1};

    Solution sol;

    cout << sol.maxProduct(nums) << endl;

    return 0;
}