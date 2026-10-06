#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#include <climits>
#include <numeric>
#include <utility>
#include <functional>
#include <bitset>
#include <cstring>
using namespace std;

#define debug(x) cerr << #x << " = " << (x) << "\n"
#define debugArr(a, n)                               \
    cerr << #a << " = [";                            \
    for (int i = 0; i < (n); i++)                    \
        cerr << (a)[i] << (i + 1 < (n) ? ", " : ""); \
    cerr << "]\n"
#define debugVec(v)        \
    cerr << #v << " = [";  \
    for (auto &i : v)      \
        cerr << i << ", "; \
    cerr << "]\n"

long long slinding_window_algorithm(vector<int> &arr, int k)
{
    int n = arr.size();

    long long windowSum = 0;
    long long maxSum = 0;

    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {

        debug(arr[i]);
        debug(freq[arr[i]]);
        debug(windowSum);
        debug(maxSum);
        freq[arr[i]]++;

        windowSum += arr[i];

        if (i >= k)
        {
            freq[arr[i - k]]--;
            windowSum -= arr[i - k];
        }

        if (i >= k - 1)
        {
            if (freq.size() == k)
                maxSum = std::max(maxSum, windowSum);
        }
    }

    return maxSum;
}

int main()
{
    vector<int> arr = {9, 9, 9, 1, 2, 3};
    int k = 3;

    cout << slinding_window_algorithm(arr, k) << endl;
    return 0;
}