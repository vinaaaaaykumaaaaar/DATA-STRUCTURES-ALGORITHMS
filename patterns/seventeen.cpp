/*

QUESTION : Pattern 17

SAMPLE INPUT :
EXPECTED ANSWER :

*/

#include <iostream>

using namespace std;
using ll = long long;

void solve()
{
    int N = 5;
    // Initial spaces for upper half
    int iniS = 0;

    // Loop for upper half rows
    for (int i = 0; i < N; i++)
    {
        // Print stars on left
        for (int j = 1; j <= N - i; j++)
        {
            cout << "*";
        }
        // Print spaces in middle
        for (int j = 0; j < iniS; j++)
        {
            cout << " ";
        }
        // Print stars on right
        for (int j = 1; j <= N - i; j++)
        {
            cout << "*";
        }
        // Increase middle spaces by 2
        iniS += 2;
        // Move to next row
        cout << endl;
    }

    // Initial spaces for lower half
    iniS = 2 * N - 2;

    // Loop for lower half rows
    for (int i = 1; i <= N; i++)
    {
        // Print stars on left
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        // Print spaces in middle
        for (int j = 0; j < iniS; j++)
        {
            cout << " ";
        }
        // Print stars on right
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        // Decrease middle spaces by 2
        iniS -= 2;
        // Move to next row
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