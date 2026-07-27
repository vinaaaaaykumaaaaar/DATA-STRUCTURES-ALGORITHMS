#include <bits/stdc++.h>

using namespace std;

int binary_search(const vector<int> &nums, int target)
{
    if (nums.empty())
        return -1;

    int l = 0, r = (int)nums.size() - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (nums[m] == target)
            return m;
        if (nums[m] < target)
            l = m + 1;
        else
            r = m - 1;
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a = {-10, -3, 0, 5, 9, 12, 19};
    cout << binary_search(a, 20) << "\n";
    return 0;
}