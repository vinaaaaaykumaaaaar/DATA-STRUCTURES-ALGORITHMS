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

    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = i; j < a.size(); ++j)
        {
            for (int k = i; k <= j; ++k)
            {
                cout << a[k] << " ";
            }
            cout << endl;
        }
    }
}

vector<vector<int>> helper(vector<int> &a, int i)
{
    if (i >= a.size())
        return {{}};

    vector<vector<int>> partial = helper(a, i + 1);

    vector<vector<int>> ans;

    for (auto x : partial)
        ans.push_back(x);

    for (auto x : partial)
        x.push_back(a[i]), ans.push_back(x);

    return ans;
}

void recursive(vector<int> &a)
{

    vector<vector<int>> ans = helper(a, 0);

    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}

void recurion(vector<int> &a, int i, vector<int> &subset, vector<vector<int>> &ans)
{

    if (i == a.size())
    {
        ans.push_back(subset);
        return;
    }

    // have to include ith element
    subset.push_back(a[i]);
    recurion(a, i + 1, subset, ans);

    // not to include ith element
    subset.pop_back();
    recurion(a, i + 1, subset, ans);
}

void optimal_recursion(vector<int> &a)
{
    vector<vector<int>> ans;
    vector<int> subset;

    recurion(a, 0, subset, ans);

    for (auto x : ans)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
}

int main()
{

    vector<int> a = {1, 2, 3};
    vector<int> b = {1, 2};
    vector<int> c = {1, 2, 3, 4};

    cout << "-----------------------------------" << endl;
    optimal_recursion(a);
    cout << "-----------------------------------" << endl;
    optimal_recursion(b);
    cout << "-----------------------------------" << endl;
    optimal_recursion(c);
    cout << "-----------------------------------" << endl;
    return 0;
}