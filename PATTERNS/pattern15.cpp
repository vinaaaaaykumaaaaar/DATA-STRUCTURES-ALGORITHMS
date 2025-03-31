#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 5; i++)
    {
        int c = 65;

        for (int j = 0; j < 5 - i; j++)
        {
            cout << char(c);
            c++;
        }
        cout << endl;
    }
}