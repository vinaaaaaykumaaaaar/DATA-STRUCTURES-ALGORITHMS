#include <iostream>
#include <array>
#include <vector>
using namespace std;

vector<int> a = {1, 2, 3, 4, 5};
int key = 0;

// BINARY SEARCH USING ITERATIVE METHOD
int iterative(vector<int> &a, int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == key)
            return mid;
        else if (key > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// BINARY SEARCH USING RECURSION METHOD

int recursive(int low, int high)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;
    if (a[mid] == key)
        return mid;
    if (a[mid] < key)
        recursive(mid + 1, high);
    else
        recursive(low, mid - 1);
}

int main()
{

    // int result = iterative(a, a.size(), key);
    // cout << "Key was found at " << result;

    int result = recursive(0, a.size() - 1);
    result == -1 ? cout << "Key not found " : cout << "key found at " << result + 1;
}
