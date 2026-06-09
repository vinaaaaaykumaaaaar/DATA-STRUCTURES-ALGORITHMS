
#include <iostream>
using namespace std;

int main()
{
    int n = 5;

    for (int i = 0; i < 2 * n - 1; i++)
    {
        int spaces = (i < n) ? n - 1 - i : i - n + 1;
        int stars = (i < n) ? 2 * i + 1 : 2 * (2 * n - 2 - i) + 1;

        for (int j = 0; j < spaces; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < stars; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}
