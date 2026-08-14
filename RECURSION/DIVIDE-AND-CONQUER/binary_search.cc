#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> &a, int t, int l, int h)
{
    int m = l + (h - l) / 2;
    if (l < h)
    {
        if (a[m] == t)
            return m;
        else if (a[m] > t)
            binary_search(a, t, l, m - 1);
        else
            binary_search(a, t, m + 1, h);
    }
    return -1;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int target = 10;
    cout << binary_search(arr, target, 0, arr.size() - 1) << endl;

    return 0;
}