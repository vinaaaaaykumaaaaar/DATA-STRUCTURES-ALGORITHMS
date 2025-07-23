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

    int i = 0, l = a.size() - 1;
    while (i <= l)
    {
        swap(a[i], a[l]);
        ++i, --l;
    }

    for (auto x : a)
        cout << x << " ";
    cout << endl;
}

int main()
{

    vector<int> a = {1, 2, 3};
    vector<int> b = {1, 2};
    vector<int> c = {1, 2, 3, 4};

    cout << "-----------------------------------" << endl;
    solve(a);
    cout << "-----------------------------------" << endl;
    solve(b);
    cout << "-----------------------------------" << endl;
    solve(c);
    cout << "-----------------------------------" << endl;
    return 0;
}