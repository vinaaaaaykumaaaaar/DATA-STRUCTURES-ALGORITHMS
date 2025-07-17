#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <list>

using namespace std;

void solve(vector<int> &a)
{

    queue<int> p, s;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < 1)
            s.push(a[i]);
        else
            p.push(a[i]);
    }

    for (int i = 0; i < a.size(); i++)
    {
        if (i & 1)
            a[i] = p.front(), p.pop();
        else
            a[i] = s.front(), s.pop();
    }

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
}

void optimal(vector<int> &a)
{

    vector<int> ans(a.size(), 0);
    int p = 0;
    int n = 1;

    for (auto x : a)
    {
        if (x < 0)
            ans[n] = x, n += 2;
        else
            ans[p] = x, p += 2;
    }

    for (auto x : ans)
    {
        cout << x << " ";
    }

    cout << endl;
}

int main()
{

    vector<int> a = {3, 1, -2, -5, 2, -4};
    int n, m, i, k;

    solve(a);
    optimal(a);
    return 0;
}

// 3 1 -2 -5 2 -4 -> -2 3 -5 1 -4 2