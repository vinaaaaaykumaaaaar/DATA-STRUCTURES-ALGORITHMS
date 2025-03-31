#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 10; i++)
    {

        if (i < 5)
        {
            for (int j = 5; j > i; j--)
                cout << " ";

            for (int j = 0; j < 2 * i - 1; j++)
                cout << "*";
        }
        else
        {
            for (int j = 5; j > i; j--)
                cout << " ";

            for (int j = 0; j < 2 * i - 1; j++)
                cout << "*";
        }

        cout << "\n";
    }
}