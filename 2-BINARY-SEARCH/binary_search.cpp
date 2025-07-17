#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <list>

using namespace std;

int binary(vector<int> &a, int s, int e, int t)
{

    if (s > e)
        return -1;
    int m = (s + e) / 2;

    if (a[m] == t)
        return m;
    else if (a[m] > t)
        return binary(a, s, m - 1, t);
    else
        return binary(a, m + 1, e, t);
}

int main()
{

    vector<int> a = {1, 2, 3, 4, 5, 6};
    int n, m, i, k;

    cout << binary(a, 0, a.size() - 1, 6);

    return 0;
}

// 3 1 -2 -5 2 -4 -> -2 3 -5 1 -4 2