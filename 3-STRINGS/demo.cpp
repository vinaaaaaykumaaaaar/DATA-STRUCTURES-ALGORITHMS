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

void solve(string &name)
{

    unordered_map<char, int> m;
    vector<pair<char, int>> p;
    for (auto x : name)
        m[x]++;

    for (auto x : m) // structured binding (C++17)
        p.push_back({x.first, x.second});

    auto cmp = [&](pair<char, int> &a, pair<char, int> &b)
    {
        return a.second > b.second;
    };

    sort(p.begin(), p.end(), cmp);

    string ans = "";

    for (auto x : p)
        ans.append(x.second, x.first);

    cout << ans << endl;
}

int main()
{

    string name = "abbA";
    int n, m, i, k;

    solve(name);
    return 0;
}