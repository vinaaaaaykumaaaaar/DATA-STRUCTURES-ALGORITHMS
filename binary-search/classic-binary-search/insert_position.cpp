#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int insert_position(vector<int> &arr, int ele)
{
    int n = arr.size();

    int left = 0, right = n - 1, ans = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == ele)
        {
            return mid;
        }
        else if (arr[mid] < ele)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return left;
}

int main()
{
    vector<int> arr = {1, 3, 5, 6};
    int k = 4;

    cout << insert_position(arr, k) << endl;

    return 0;
}