#include <stdio.h>
#include <string.h>

void vulnerable()
{
    char buffer[8]; // only 8 bytes
    printf("Enter a string: ");
    gets(buffer); // DANGER: no size limit!
    printf("You entered: %s\n", buffer);
}

int main()
{
    vulnerable();
    return 0;
}