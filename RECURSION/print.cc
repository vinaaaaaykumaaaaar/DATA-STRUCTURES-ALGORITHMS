#include <iostream>

void print(int n)
{
    if (n <= 0)
        return;

    printf("%d ", n);

    print(n - 1);
}

int main()
{
    int n = 10;

    print(n);

    return 0;
}