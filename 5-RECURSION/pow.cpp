// RECURSIVE IMPLEMENTATION OF POW( x , n )

#include <iostream>

// function to implement the pow
int powerFunction(int n, int p)
{
    if (p == 1)
        return n;

    return n * powerFunction(n, p - 1);
}

int main()
{
    int number = 0, power = 1;
    std::cin >> number >> power;

    int result = powerFunction(number, power);
    std::cout << result << std::endl;

    return 0;
}