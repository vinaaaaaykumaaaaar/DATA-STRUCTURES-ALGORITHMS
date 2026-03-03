/*

QUESTION : Pattern 16

SAMPLE INPUT :
EXPECTED ANSWER :
A
B B
C C C
D D D D
E E E E E

*/

#include <iostream>

using namespace std;
using ll = long long;

void solve()
{
    int n = 5;
    char character = 'A';

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << char(character + i) << " ";
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