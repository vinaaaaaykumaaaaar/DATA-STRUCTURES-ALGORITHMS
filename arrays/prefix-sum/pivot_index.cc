#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#include <climits>
#include <numeric>
#include <utility>
#include <functional>
#include <bitset>
#include <cstring>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();
        int totalSum = 0, leftSum = 0;

        for (int num : nums)
            totalSum += num;

        for (int i = 0; i < n; ++i)
        {
            if (leftSum == (totalSum - leftSum - nums[i]))
                return i;
            leftSum += nums[i];
        }

        return -1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr = {2, 1, -1};

    Solution s;
    cout << s.pivotIndex(arr) << endl;

    return 0;
}