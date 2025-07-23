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
    int l = -1, sl = -1;

    for (auto x : a)
    {
        if (x > l)
            sl = l, l = x;
        else if (x < l && x > sl)
            sl = x;
    }

    cout << sl << endl;
}

int main()
{

    vector<int> a = {
        10, 10, 10};

    solve(a);
    return 0;
}