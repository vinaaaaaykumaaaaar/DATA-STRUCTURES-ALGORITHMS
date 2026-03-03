/*

QUESTION : Pattern 10 tuf

SAMPLE INPUT :
EXPECTED ANSWER :

*
**
***
****
*****
****
***
**
*

*/

#include <iostream>

using namespace std;
using ll = long long;

void solve()
{
    int n = 5;

    for (int i = 1; i <= 2 * n - 1; i++)
    {
        for (int j = 1; j <= n - abs(n - i); j++)
        {
            cout << "*";
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