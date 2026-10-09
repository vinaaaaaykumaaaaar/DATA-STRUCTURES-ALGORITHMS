#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int brute_force(vector<int> &arr, int k)
{

    int maxCount = 0;

    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        int zeros = 0;
        for (int j = i; j < n; j++)
        {

            if (arr[j] == 0)
                zeros++;
            if (zeros > k)
                break;
            count++;
        }
        maxCount = max(maxCount, count);
    }

    return maxCount;
}

int sliding_window(vector<int> &arr, int target)
{
    int left = 0, right = 0, maxCount = 0, zeros = 0;

    while (right < arr.size())
    {
        if (arr[right] == 0)
            zeros++;
        if (zeros > target)
        {
            while (zeros > target)
            {
                if (arr[left] == 0)
                    zeros--;
                left++;
            }
        }
        maxCount = max(maxCount, (right - left + 1));
        right++;
    }

    return maxCount;
}

int main()
{
    vector<int> arr = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;

    // cout << brute_force(arr, k) << endl;
    cout << sliding_window(arr, k) << endl;

    return 0;
}