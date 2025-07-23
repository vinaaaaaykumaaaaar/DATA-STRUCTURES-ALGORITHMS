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

string solve(vector<int> &a, int t)
{

    for (auto x : a)
        if (x == t)
            return "found";
    return "not found";
}

int main()
{

    vector<int> a = {10, 20, 30, 40, 50};

    cout << solve(a, -1) << endl;
    return 0;
}