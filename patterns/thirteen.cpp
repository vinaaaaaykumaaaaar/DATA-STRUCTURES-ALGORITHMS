/*

QUESTION : Pattern 13

SAMPLE INPUT :
EXPECTED ANSWER :

1
2 3
4 5 6
7 8 9 10
11 12 13 14 15

*/

#include <iostream>

using namespace std;
using ll = long long;

void solve()
{
    int n = 5;
    int64_t number = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << number << " ";
            number = number + 1;
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