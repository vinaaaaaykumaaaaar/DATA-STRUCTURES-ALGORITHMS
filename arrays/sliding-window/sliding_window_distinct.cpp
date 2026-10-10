#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

int brute_force(vector<int> &arr, int k)
{
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; ++i)
    {
        unordered_map<int, int> freq;
        for (int j = i; j < n; ++j)
        {
            freq[arr[j]]++;

            if (freq.size() == k)
                count++;
        }
    }

    return count;
}

int sliding_window(vector<int> &arr, int k)
{
    int n = arr.size();
    int l = 0, r = 0;

    int count = 0;

    unordered_map<int, int> f;

    while (r < n)
    {
        f[arr[r]]++;

        while (f.size() > k && l <= r)
        {
            f[arr[l]]--;

            if (f[arr[l]] == 0)
                f.erase(arr[l]);
            l++;
        }

        count += (r - l + 1);

        r++;
    }

    return count;
}

int main()
{
    vector<int> arr = {1, 2, 1, 2, 3};
    int k = 2;

    // cout << brute_force(arr, k) << endl;
    cout << sliding_window(arr, k) << endl;

    return 0;
}
