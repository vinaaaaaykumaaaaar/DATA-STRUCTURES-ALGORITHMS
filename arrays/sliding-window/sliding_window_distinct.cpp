#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

int brute_force(vector<int> &arr, int k)
{
    int n = arr.size();

    for (int i = 0; i < n; ++i)
    {
        unordered_map<int, int> freq;
        for (int j = i; j < n; ++j)
        {
            freq[arr[j]]++;
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 1, 2, 3};
    int k = 2;

    cout << brute_force(arr, k) << endl;

    return 0;
}
