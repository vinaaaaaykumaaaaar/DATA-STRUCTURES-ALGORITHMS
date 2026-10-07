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
    }
}

int main()
{
    vector<int> arr = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k = 3;

    cout << brute_force(arr, k) << endl;

    return 0;
}