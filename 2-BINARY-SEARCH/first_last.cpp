#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <list>

using namespace std;

int upper(vector<int> &a, int s, int e, int t)
{
    int ans = e; // Initialize ans (or could be a.size() if searching entire array)

    while (s <= e)
    {
        int m = s + (e - s) / 2; // Avoid potential overflow

        if (a[m] > t)
        {
            ans = m;
            e = m - 1; // Search left half
        }
        else
        {
            s = m + 1; // Search right half
        }
    }

    return ans;
}

int lower(vector<int> &a, int s, int e, int t)
{
    int ans = e; // Initialize ans (or could be a.size() if searching entire array)

    while (s <= e)
    {
        int m = s + (e - s) / 2; // Avoid potential overflow

        if (a[m] >= t)
        {
            ans = m;
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
    vector<int> a = {2, 4, 6, 8, 8, 8, 11, 13};

    cout << lower(a, 0, a.size() - 1, 8) << " " << upper(a, 0, a.size() - 1, 8) - 1 << endl; // Pass a.size()-1, not a.size()
    return 0;
}