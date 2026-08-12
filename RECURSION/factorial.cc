#include <iostream>

using namespace std;

int factorial(int val)
{
    if (val <= 1)
        return 1;

    return val * factorial(val - 1);
}

int main()
{
    int n = 10;
    cout << factorial(n) << endl;

    return 0;
}
