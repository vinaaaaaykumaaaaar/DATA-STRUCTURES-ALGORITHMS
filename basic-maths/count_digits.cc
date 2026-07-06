#include <iostream>
using namespace std;

int main()
{
    int n = 12345;
    int c = 0;

    while (n)
    {
        c++;
        n = n / 10;
    }

    cout << c << endl;
}