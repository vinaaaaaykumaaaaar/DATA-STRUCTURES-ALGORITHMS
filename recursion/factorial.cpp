#include <iostream>

long long factorial(int n)
{
    if (n <= 1)
        return 1;                // base case
    return n * factorial(n - 1); // recursive case
}

int main()
{
    int n = 5;
    std::cout << n << "! = " << factorial(n) << "\n";
}