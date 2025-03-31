#include <iostream>
using namespace std;

int main()
{
    int space = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 5 - i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < space; j++)
        {
            cout << " ";
        }
        space += 2;
        for (int j = 0; j < 5 - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}