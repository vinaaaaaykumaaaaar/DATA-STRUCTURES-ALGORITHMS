#include <iostream>

int sum(int number)
{
    if (number <= 0)
        return 0;
    if (number == 1)
        return 1;

    return number + sum(number - 1);
}

int main()
{
    int number = 0;

    std::cout << "Enter the number" << std::endl;
    std::cin >> number;

    std::cout << sum(number) << std::endl;

    return 0;
}