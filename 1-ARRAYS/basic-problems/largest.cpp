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

int solve(vector<int> &a)
{
    int m = INT32_MIN;
    for (auto x : a)
        m = max(x, m);
    return m;
}

int main()
{

    vector<int> a = {2, 4, 10, -1, 6};

    cout << solve(a) << endl;
    return 0;
}