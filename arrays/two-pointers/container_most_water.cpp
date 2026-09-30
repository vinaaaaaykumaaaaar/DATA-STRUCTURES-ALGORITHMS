#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int> &height)
{
    int n = height.size();

    int begin = 0, end = n - 1;

    int maximumArea = 0;

    while (begin < end)
    {
        int length = (end - begin);
        int breadth = min(height[end], height[begin]);

        int currentMaximumArea = length * breadth;

        maximumArea = max(maximumArea, currentMaximumArea);

        if (height[begin] <= height[end])
            begin++;
        else
            end--;
    }

    return maximumArea;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << maxArea(height) << endl;
}