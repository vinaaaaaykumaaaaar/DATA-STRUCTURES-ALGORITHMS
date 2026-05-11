
/*
1299. Replace Elements with Greatest Element on Right Side
Solved
Easy
Topics
premium lock icon
Companies
Hint
Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.



Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
Explanation:
- index 0 --> the greatest element to the right of index 0 is index 1 (18).
- index 1 --> the greatest element to the right of index 1 is index 4 (6).
- index 2 --> the greatest element to the right of index 2 is index 4 (6).
- index 3 --> the greatest element to the right of index 3 is index 4 (6).
- index 4 --> the greatest element to the right of index 4 is index 5 (1).
- index 5 --> there are no elements to the right of index 5, so we put -1.
Example 2:

Input: arr = [400]
Output: [-1]
Explanation: There are no elements to the right of index 0.


Constraints:

1 <= arr.length <= 104
1 <= arr[i] <= 105
*/

#include <bits/stdc++.h>
using namespace std;

// debug macro

void _debug_print() { cerr << endl; }

template <typename T, typename... Args>
void _debug_print(T t, Args... args)
{
    cerr << t << " ";
    _debug_print(args...);
}

#define debug(...)                             \
    do                                         \
    {                                          \
        cerr << "[" << #__VA_ARGS__ << "] = "; \
        _debug_print(__VA_ARGS__);             \
        cerr << endl;                          \
    } while (0)

// solution class

class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        vector<int> res;

        int max = arr[arr.size() - 1];

        res.push_back(-1);

        for (int i = arr.size() - 1; i > 0; i--)
        {
            debug(max);
            if (arr[i] >= max)
            {
                max = arr[i];
                res.push_back(max);
            }
            else
                res.push_back(max);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
// main function

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    // int T = 1;
    // // cin >> T;
    // int input;

    vector<int> arr = {17, 18, 5, 4, 6, 1};

    vector<int> res = sol.replaceElements(arr);

    for (auto x : res)
        cout << x << " ";

    return 0;
}