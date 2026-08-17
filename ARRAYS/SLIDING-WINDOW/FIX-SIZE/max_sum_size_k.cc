#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_sum(vector<int> &arr, int k)
{
    int max_sum = -33544564;
    int window_sum = 0;
    int start = 0;

    for (int end = 0; end < arr.size(); end++)
    {
        window_sum += arr[end];

        if (end - start + 1 == k)
        {
            max_sum = max(max_sum, window_sum);
            window_sum -= arr[start];
            start++;
        }
    }

    return max_sum;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;

    cout << max_sum(arr, k) << "\n";

    return 0;
}