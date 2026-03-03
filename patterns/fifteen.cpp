/*

QUESTION : Pattern 15

SAMPLE INPUT :
EXPECTED ANSWER :
A B C D E
A B C D
A B C
A B
A
*/

#include <iostream>

using namespace std;
using ll = long long;

void solve()
{
    int n = 5;

    for (int i = 1; i <= n; i++)
    {
        for (char character = 'A'; character <= 'A' + (n - i); character++)
        {
            cout << character << " ";
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