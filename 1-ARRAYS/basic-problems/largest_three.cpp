#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <unordered_map>

using namespace std;

void solve(vector<int> &a)
{

    int l = -1, s = -1, t = -1;
    if (a.size() <= 3)
    {
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        for (auto x : a)
            cout << x << " ";
        cout << endl;

        return;
    }

    for (auto x : a)
    {
        if (x > l)
            t = s, s = l, l = x;
        else if (x < l && x > s)
            t = s, s = x;
        else if (x < l && x < s && x > t)
            t = x;
    }

    cout << l << " " << s << " " << t << endl;
}

int main()
{

    vector<int> a = {10, 4, 3, 50, 23, 90};
    vector<int> v = {10, 9, 9};

    solve(a);
    solve(v);
    return 0;
}