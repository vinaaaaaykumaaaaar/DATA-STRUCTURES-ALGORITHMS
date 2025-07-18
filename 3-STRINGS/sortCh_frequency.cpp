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
    for (auto x : name)
        m[x]++;

    vector<vector<char>> b(name.length() + 1);
    for (auto x : m)
        b[x.second].push_back(x.first);
    string ans = "";

    for (int i = name.size(); i >= 0; --i)
    {
        for (auto ch : b[i])
            ans.append(i, ch);
    }

    cout << ans << endl;
}
int main()
{

    string name = "abb";

    solve(name);
    return 0;
}