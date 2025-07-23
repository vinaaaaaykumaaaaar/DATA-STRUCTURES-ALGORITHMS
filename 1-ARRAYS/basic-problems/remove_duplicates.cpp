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

    vector<int> v;
    if (a.size() <= 1)
    {
        for (auto x : a)
            cout << x << " ";
        cout << endl;
        return;
    }

    v.push_back(a[0]);
    for (auto i = 1; i < a.size(); i++)
        if (a[i] != a[i - 1])
            v.push_back(a[i]);

    for (auto x : v)
        cout << x << " ";
    cout << endl;
}

int main()
{

    vector<int> a = {2, 2, 2, 2, 2};
    vector<int> v = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    vector<int> b = {1, 2, 3};

    solve(a);
    solve(v);
    solve(b);
    return 0;
}