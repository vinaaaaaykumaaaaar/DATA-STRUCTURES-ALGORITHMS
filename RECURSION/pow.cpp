#include <iostream>
#include <cmath>
using namespace std;

double myPowBruteForce(double x, int n)
{
    if (n == 0)
        return 1.0;

    if (x == 0.0)
    {
        if (n < 0)
            return INFINITY;
        return 0.0;
    }

    long long N = n;
    if (N < 0)
        N = -N;

    double result = 1.0;

    for (long long i = 0; i < N; i++)
    {
        result *= x;
    }

    if (n < 0)
    {
        result = 1.0 / result;
    }

    return result;
}

int main()
{
    cout << myPowBruteForce(2.0, 10) << endl; // 1024
    cout << myPowBruteForce(2.0, -2) << endl; // 0.25
    cout << myPowBruteForce(2.1, 3) << endl;  // 9.261

    return 0;
}