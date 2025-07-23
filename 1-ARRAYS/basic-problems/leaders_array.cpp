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

    if (a.size() <= 1)
    {
        for (auto x : a)
            cout << x << " ";
        cout << endl;
    }
    int m = INT32_MIN;
    vector<int> v;
    for (int i = a.size() - 1; i >= 0; --i)
        if (a[i] > m)
            v.push_back(a[i]), m = a[i];

    reverse(v.begin(), v.end());

    for (auto x : v)
        cout << x << " ";
    cout << endl;
}

int main()
{

    vector<int> a = {16, 17, 4, 3, 5, 2};
    vector<int> v = {1, 2, 3, 4, 5, 2};

    solve(a);
    solve(v);
    return 0;
}