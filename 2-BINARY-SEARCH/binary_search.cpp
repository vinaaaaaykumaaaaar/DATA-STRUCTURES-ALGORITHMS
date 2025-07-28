#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <list>

using namespace std;

int binary_iterative(vector<int> &a, int target)
{

    int high = a.size() - 1, low = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == target)
        {
            return mid + 1;
        }
        else if (a[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int binary_recursive(vector<int> &a, int start, int end, int target)
{

    if (start > end)
    {
        return -1;
    }
    int mid = (start + end) / 2;
    if (a[mid] == target)
    {
        return mid + 1;
    }
    else if (a[mid] > target)
    {
        binary_recursive(a, start, mid - 1, target);
    }
    else
    {
        binary_recursive(a, mid + 1, end, target);
    }
}

int main()
{

    vector<int> a = {1, 2, 3, 4, 5, 6};

    cout << binary_iterative(a, 7) << endl;
    cout << binary_recursive(a, 0, a.size() - 1, 7) << endl;

    return 0;
}
