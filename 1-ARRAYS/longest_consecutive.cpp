#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <list>

using namespace std;

void solve(vector<int> &a)
{

    int ls = -100, c = 0, l = 1;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] - 1 == ls)
        {
            c++;
            ls = a[i];
        }
        else if (ls != a[i])
        {
            c = 1;
            ls = a[i];
        }

        l = max(l, c);
    }

    cout << l << endl;
}

void optimal(vector<int> &a)
{
}

int main()
{

    vector<int> a = {100, 102, 100, 101, 101, 4, 3, 2, 3, 2, 1, 1, 1, 2};
    int n, m, i, k;

    solve(a);
    // optimal(a);
    return 0;
}

// 3 1 -2 -5 2 -4 -> -2 3 -5 1 -4 2