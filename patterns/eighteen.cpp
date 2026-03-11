/*

QUESTION :

SAMPLE INPUT :
EXPECTED ANSWER :

****
*  *
*  *
****

*/

#include <iostream>

using namespace std;
using ll = long long;

void solve()
{

    int n = 4;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n;j++)
        {
            if(i == 0 || i== 3 || j == 0 || j==3)
            {
                cout << "*";
            }
            else{
                cout << " ";
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