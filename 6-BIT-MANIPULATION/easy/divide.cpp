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

void solve(int d, int s)
{
    int c = 0, S = 0;
    while (S + s <= d)
    {
        ++c;
        S += s;
    }

    cout << c << endl;
}

int main()
{

    int d = 22, s = 3;

    solve(d, s);
    return 0;
}