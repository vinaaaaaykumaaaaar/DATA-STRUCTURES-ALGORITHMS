#include <iostream>
#include <vector>
using namespace std;

int bruteforceFibo(int n)
{
    vector<int> fib(n + 1, 0);

    fib[0] = 0, fib[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

int recursion(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return recursion(n - 1) + recursion(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << recursion(n) << endl;
    return 0;
}