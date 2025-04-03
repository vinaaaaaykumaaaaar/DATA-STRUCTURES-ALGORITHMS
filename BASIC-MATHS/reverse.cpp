#include <iostream>
using namespace std;

/*
    1234 -> 123 -> 12 -> 1;
            4 -> 43 -> 432 -> 4321
*/

int main()
{
    int n;
    cin >> n;

    int rev = 0;

    while (n)
    {
        int sum = n % 10;
        rev = rev * 10 + sum;

        n = n / 10;
    }

    cout << rev;
}