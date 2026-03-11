#include <stdio.h>
#include <stdint.h>

int main()
{
    printf("short: %zu bytes\n", sizeof(short));
    printf("int: %zu bytes\n", sizeof(int));
    printf("long: %zu bytes\n", sizeof(long));
    printf("long long: %zu bytes\n", sizeof(long long));
    printf("int32_t: %zu bytes\n", sizeof(int32_t));
    printf("int64_t: %zu bytes\n", sizeof(int64_t));
}