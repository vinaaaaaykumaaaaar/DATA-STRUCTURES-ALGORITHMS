#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int assignCookie(vector<int> &g, vector<int> &s)
{
    int n = g.size(), m = s.size();

    int l = 0, r = 0;

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    while (l < m)
    {
        if (s[l] >= g[r])
        {
            r++;
        }
        l++;
    }

    return r;
}

int main()
{
    vector<int> g = {1, 5, 3, 3, 4};
    vector<int> s = {4, 2, 1, 2, 1, 3};

    cout << assignCookie(g, s) << endl;
}