#include <stdio.h>

int main()
{

    int rows;
    printf("Enter the number of rows\n");
    scanf("%i", &rows);

    for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < rows - i; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < rows; j++)
        {
            printf("%i", j + 1);
        }

        printf("\n");
    }

    return 0;
}