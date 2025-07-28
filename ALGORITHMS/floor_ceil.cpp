#include <iostream>
#include <cmath> // Required for floor() and ceil()

int main()
{
    double num1 = 4.7;
    double num2 = -3.2;

    std::cout << "floor(" << num1 << ") = " << std::floor(num1) << std::endl; // Output: 4.0
    std::cout << "ceil(" << num1 << ") = " << std::ceil(num1) << std::endl;   // Output: 5.0

    std::cout << "floor(" << num2 << ") = " << std::floor(num2) << std::endl; // Output: -4.0
    std::cout << "ceil(" << num2 << ") = " << std::ceil(num2) << std::endl;   // Output: -3.0

    return 0;
}