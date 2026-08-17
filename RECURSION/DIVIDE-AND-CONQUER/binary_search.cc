#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> &arr, int target, int start, int end)
{

    if (start > end)
        return -1;
    int mid = start + (end - start) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return binary_search(arr, target, start, mid - 1);
    else
        return binary_search(arr, target, mid + 1, end);
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int target = 4;
    cout << binary_search(arr, target, 0, arr.size() - 1) << endl;

    return 0;
}