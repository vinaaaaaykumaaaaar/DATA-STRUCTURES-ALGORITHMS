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

double powOptimal(double x, int n)
{
    long long N = n;

    double result = 1;

    if (N == 0)
        return 1;
    if (N < 0)
    {
        x = 1 / x;
        N = -N;
    }

    int count = 0;

    while (N > 0)
    {
        cout << "step " << count << ": " << "N = " << N << " x = " << x << " result = " << result << endl;
        if (N % 2 == 1)
        {
            result *= x;
        }

        x *= x;
        N /= 2;
        count++;
    }

    return result;
}

int main()
{
    // cout << myPowBruteForce(2.0, 10) << endl; // 1024
    // cout << myPowBruteForce(2.0, -2) << endl; // 0.25
    // cout << myPowBruteForce(2.1, 3) << endl;  // 9.261

    cout << powOptimal(2, 6) << endl;

    return 0;
}