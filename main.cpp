#include <stdio.h>

void printBinary(int num)
{
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--)
    {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main()
{
    int number = 10;
    printf("Binary representation of %d: ", number);
    printBinary(number);
    return 0;
}