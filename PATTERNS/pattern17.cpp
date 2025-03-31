#include <iostream>
using namespace std;

int main()
{

    for (int i = 1; i <= 5; i++)
    {
        char ch = 'A';
        int b = (2 * i - 1) / 2;
        for (int j = 1; j <= 5 - i; j++)
            cout << " ";

        for (int j = 1; j <= 2 * i - 1; j++)
        {

            cout << ch;
            if (j <= b)
                ch++;
            else
                ch--;
        }
        cout << "\n";
    }
}