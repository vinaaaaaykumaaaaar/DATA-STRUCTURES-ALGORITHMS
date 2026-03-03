/*

QUESTION : Pattern 9 TUF

SAMPLE INPUT :
EXPECTED ANSWER :

    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *

*/

#include <iostream>
using namespace std;

void star_pattern()
{
    int n = 5;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        for (int j = 1; j <= abs(n - i); j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= 2 * (n - abs(i - n)) - 1; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

int main()
{
    int n = 5;

    cout << "----------------------------------------" << endl;
    cout << "first approach : " << endl;

    // Upper half (including middle)
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
            cout << " ";
        for (int j = 1; j <= 2 * i - 1; j++)
            cout << "*";
        cout << endl;
    }

    // Lower half (excluding middle)
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= n - i; j++)
            cout << " ";
        for (int j = 1; j <= 2 * i - 1; j++)
            cout << "*";
        cout << endl;
    }

    cout << "----------------------------------------" << endl;

    cout << "second approach : " << endl;
    star_pattern();
    cout << "----------------------------------------" << endl;

    return 0;
}
