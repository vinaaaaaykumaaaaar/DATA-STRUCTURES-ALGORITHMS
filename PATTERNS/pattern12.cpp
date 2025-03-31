#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            if (j <= i || j >= 11 - i)
            {
                if (j <= i)
                    cout << j;
                else
                    cout << 11 - j;
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}