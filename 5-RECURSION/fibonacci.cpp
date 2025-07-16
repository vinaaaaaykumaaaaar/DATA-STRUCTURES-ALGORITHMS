#include <iostream>

int fibonacci(int number)
{
    if (number <= 1)
        return 1;

    return number * fibonacci(number - 1);
    return 0;
}

int main()
{
    int number = 0;
    std::cout << "Enter the number" << std::endl;
    std::cin >> number;

    std::cout << fibonacci(number) << std::endl;
    return 0;
}