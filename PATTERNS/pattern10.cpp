#include <iostream>
using namespace std;

int main()
{

    for (int i = 1; i <= 2 * 5 - 1; i++)
    {
        if (i > 5)
        {
            for (int j = 0; j < 2 * 5 - i; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
        else
        {
            for (int j = 0; j <= (2 * i - 1) / 2; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
}