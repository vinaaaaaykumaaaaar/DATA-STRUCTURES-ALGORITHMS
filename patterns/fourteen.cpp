/*

QUESTION : Pattern 14

SAMPLE INPUT :
EXPECTED ANSWER :
A
A B
A B C
A B C D
A B C D E

*/

#include <iostream>

using namespace std;
using ll = long long;

void other_solution()
{
    int n = 5;

    for (int i = 1; i <= n; i++)
    {
        for (char character = 'A'; character < 'A' + i; character++)
        {
            cout << character << " ";
        }
        cout << endl;
    }
}

void solve()
{
    int n = 5;
    char character = 'A';

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << char(character + j) << " ";
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
        other_solution();
    }

    return 0;
}