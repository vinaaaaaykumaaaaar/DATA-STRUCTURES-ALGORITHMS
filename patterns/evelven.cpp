/*

QUESTION : Pattern 11

SAMPLE INPUT :
EXPECTED ANSWER :

1
0 1
1 0 1
0 1 0 1
1 0 1 0 1

*/

#include <iostream>

using namespace std;
using ll = long long;

void solve()
{
    int n = 5;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if ((i + j) % 2 == 0)
            {
                cout << "1 ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}