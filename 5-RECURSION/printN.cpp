#include <iostream>

void print(int n)
{
    std::cout << n << std::endl;

    if (n >= 5)
        return;

    print(n + 1);
}

int main()
{
    int n = 1;

    print(n);
    return 0;
}