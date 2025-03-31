#include <iostream>
using namespace std;

int main()
{

    int start = 1243;
    for (int i = 1; i <= 5; i++)
    {
        if (i % 2 == 0)
            start = 0;
        else
            start = 1;
        for (int j = 1; j <= i; j++)
        {
            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }
}