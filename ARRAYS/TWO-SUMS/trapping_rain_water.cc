#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trapBruteForce(vector<int> &height)
{
    int n = height.size();
    if (n == 0)
        return 0;

    int totalWater = 0;

    for (int i = 0; i < n; i++)
    {
        int left = 0, right = 0;
        for (int j = 0; j <= i; j++)
        {
            left = max(left, height[j]);
        }

        for (int k = i; k < n; k++)
        {
            right = max(right, height[k]);
        }

        int currWater = min(right, left) - height[i];

        if (currWater > 0)
            totalWater += currWater;
    }

    return totalWater;
}

int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    int ans = trapBruteForce(height);
    cout << "Total trapped water: " << ans << endl; // Output: 6

    return 0;
}