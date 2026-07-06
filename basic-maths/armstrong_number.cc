#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n = 153;
    int original = n;

    int sum = 0;

    while (n)
    {
        int temp = 0;
        temp = n % 10;
        sum = sum + (temp * temp * temp);
        n = n / 10;
    }

    cout << sum << endl;
}