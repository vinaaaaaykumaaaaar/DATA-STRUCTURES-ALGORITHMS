#include <iostream>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

vector<int> brute_force(vector<int> &arr, int k)
{

    int n = arr.size();
    vector<int> result;

    for (int i = 0; i <= n - k; i++)
    {
        int maxNumber = INT_MIN;
        for (int j = i; j < i + k; j++)
        {
            maxNumber = max(maxNumber, arr[j]);
        }

        result.push_back(maxNumber);
    }

    return result;
}

vector<int> sliding_window_generated(vector<int> &nums, int k)
{
    std::vector<int> result;
    // Deque to store indices of the elements
    std::deque<int> dq;

    for (int i = 0; i < nums.size(); ++i)
    {
        // 1. Remove indices that have slid out of the current window
        if (!dq.empty() && dq.front() < i - k + 1)
        {
            dq.pop_front();
        }

        // 2. Maintain monotonic decreasing order:
        // Remove elements from the back that are smaller than the current element
        while (!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }

        // Add the current element's index to the back
        dq.push_back(i);

        // 3. Append the maximum of the current window to the result array
        // The first window finishes forming when index reaches k - 1
        if (i >= k - 1)
        {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

vector<int> sliding_window(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> result;
    deque<int> dq;

    for (int i = 0; i < n; ++i)
    {
        while (!dq.empty() && dq.front() < i - k + 1)
        {
            dq.pop_front();
        }

        while (!dq.empty() && arr[dq.back()] < arr[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= k - 1)
        {
            result.push_back(arr[dq.front()]);
        }
    }

    return result;
}

int main()
{
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};

    int k = 3;

    // vector<int> res = brute_force(arr, k);
    vector<int> res = sliding_window(arr, k);

    for (auto x : res)
        cout << x << " ";
    cout << endl;

    return 0;
}