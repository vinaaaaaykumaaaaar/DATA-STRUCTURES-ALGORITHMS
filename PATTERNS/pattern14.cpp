#include <iostream>
using namespace std;

int main()
{

    for (int i = 1; i <= 5; i++)
    {
        int c = 65;
        for (int j = 1; j <= i; j++)
        {
            cout << char(c);
            c++;
        }
        cout << endl;
    }
}