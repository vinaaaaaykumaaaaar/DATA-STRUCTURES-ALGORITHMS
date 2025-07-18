#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <list>

using namespace std;

int solve(vector<int> &a, int s, int e, int t)
{
    int ans = e; // Initialize ans (or could be a.size() if searching entire array)

    while (s <= e)
    {
        int m = s + (e - s) / 2; // Avoid potential overflow

        if (a[m] > t)
        {
            ans = m;
            cout << m << endl;
            e = m - 1; // Search left half
        }
        else
        {
            s = m + 1; // Search right half
        }
    }

    return ans;
}

int main()
{
    vector<int> a = {3, 5, 8, 15, 19};

    cout << solve(a, 0, a.size() - 1, 9) << endl; // Pass a.size()-1, not a.size()
    return 0;
}