#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    int c = 'A';
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << char(c + j);
        }

        cout << endl;
    }
}