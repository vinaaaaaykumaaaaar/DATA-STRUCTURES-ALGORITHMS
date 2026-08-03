#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int currentMax = 0;

    int left = 0, right = heights.size() - 1;

    while (left < right)
    {
        int widht = right - left;
        int height = min(heights[left], heights[right]);
        int currentArea = widht * height;

        currentMax = max(currentArea, currentMax);

        if (heights[left] < heights[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    cout << currentMax << endl;

    return 0;
}