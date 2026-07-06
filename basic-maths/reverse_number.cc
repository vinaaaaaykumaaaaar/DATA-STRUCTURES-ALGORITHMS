#include <iostream>
using namespace std;

int main()
{
    int n = 12345;
    int temp = 0;

    while (n)
    {
        temp = temp * 10 + (n % 10);
        n = n / 10;
    }

    cout << temp << endl;
}