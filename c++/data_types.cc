#include <iostream>
#include <climits>
/*
| Category       | Types                                                                                |
| -------------- | ------------------------------------------------------------------------------------ |
| Integer        | `short`, `int`, `long`, `long long`                                                  |
| Unsigned       | `unsigned short`, `unsigned int`, `unsigned long`, `unsigned long long`              |
| Floating Point | `float`, `double`, `long double`                                                     |
| Character      | `char`, `signed char`, `unsigned char`, `wchar_t`, `char8_t`, `char16_t`, `char32_t` |
| Boolean        | `bool`                                                                               |
| Void           | `void`                                                                               |
| Null           | `nullptr_t`                                                                          |

*/

int main()
{
    // integer data_types
    short a = 10;
    int b = 10;
    long c = 10;
    long long d = 10;

    std::cout << "-------------- integer datatype --------------" << std::endl;
    std::cout << sizeof(a) << std::endl;
    std::cout << sizeof(b) << std::endl;
    std::cout << sizeof(c) << std::endl;
    std::cout << sizeof(d) << std::endl;
    std::cout << INT_MAX << std::endl;

    // unsigned integer datatypes

    unsigned short e = 10;
    unsigned int f = 10;
    unsigned long g = 10;
    unsigned long long h = 10;

    std::cout << "-------------- unsigned integer datatype --------------" << std::endl;
    std::cout << sizeof(e) << std::endl;
    std::cout << sizeof(f) << std::endl;
    std::cout << sizeof(g) << std::endl;
    std::cout << sizeof(h) << std::endl;

    // floating datatypes

    float i = 10;
    double j = 10;
    long double k = 10;

    std::cout << "-------------- floating datatype --------------" << std::endl;
    std::cout << sizeof(i) << std::endl;
    std::cout << sizeof(j) << std::endl;
    std::cout << sizeof(k) << std::endl;

    // character datatypes

    char l = 'A';

    std::cout << "--------------  character datatype --------------" << std::endl;
    std::cout << sizeof(l) << std::endl;

    // boolean datatypes

    bool m = 'A';

    std::cout << "--------------  boolean datatype --------------" << std::endl;
    std::cout << sizeof(m) << std::endl;
}