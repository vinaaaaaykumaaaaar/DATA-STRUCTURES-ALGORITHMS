#include <iostream>
#include <string>
#include <algorithm>

// Converts a decimal string to an integer using std::stoi
int stringToDigits(const std::string &number)
{
    try
    {
        return std::stoi(number);
    }
    catch (const std::invalid_argument &)
    {
        std::cerr << "Invalid input: not a number." << std::endl;
        return 0;
    }
    catch (const std::out_of_range &)
    {
        std::cerr << "Input number is out of range." << std::endl;
        return 0;
    }
}

// Converts an integer to its binary string representation
std::string decimalToBinary(int number)
{
    if (number == 0)
        return "0";
    std::string res;
    while (number > 0)
    {
        res += (number % 2) ? '1' : '0';
        number /= 2;
    }
    std::reverse(res.begin(), res.end());
    return res;
}

int main()
{
    std::string number;
    std::cout << "Enter a decimal number: ";
    std::cin >> number;

    int convertedNumber = stringToDigits(number);
    if (convertedNumber == 0 && number != "0")
    {
        // Error already printed in stringToDigits
        return 1;
    }

    std::string binaryNumber = decimalToBinary(convertedNumber);
    std::cout << "Binary format of " << number << " is " << binaryNumber << std::endl;

    return 0;
}