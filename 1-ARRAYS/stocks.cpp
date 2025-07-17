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

    int m = a[0], p = 0;
    for (int i = 1; i < a.size(); i++)
    {
        int c = a[i] - m;
        p = max(c, p);
        m = min(a[i], m);
    }

    cout << "hello world" << endl;

    cout << p << " " << m << endl;
}

int main()
{

    vector<int> a = {7, 1, 5, 3, 6, 2, 4};

    solve(a);
    return 0;
}