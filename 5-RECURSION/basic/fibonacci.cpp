#include <iostream>

int fibonacci(int number)
{
    if (number == 0)
        return 0;
    if (number == 1)
        return 1;

    return fibonacci(number - 1) + fibonacci(number - 2);
}

int main()
{
    int number = 0;
    std::cout << "Enter the number" << std::endl;
    std::cin >> number;

    std::cout << fibonacci(number) << std::endl;
    return 0;
}