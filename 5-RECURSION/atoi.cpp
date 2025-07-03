//  RECURSIVE IMPLEMENTATION OF ATOI ( ASCII TO INTEGER ):
//  NOTE : this problem assumes only the positive string of numbers as input

#include <iostream>
#include <string>

// helper function to convert char to integer
int charToInteger(char c)
{
    return c - '0';
}

// Recursive function to convert a string to integer
int recursiveAtoi(const std::string &str, int index)
{
    // base case: If we've reached the begin of the string
    if (index < 0)
        return 0;

    int lastDigit = charToInteger(str[index]);

    int remainingValue = recursiveAtoi(str, index - 1);

    return remainingValue * 10 + lastDigit;
}

// Main function to initiate the recursive atoi function
int atoiRecursive(std::string str)
{
    if (str.empty())
        return 0;

    return recursiveAtoi(str, str.length() - 1);
}

int main()
{
    std::string numStr;
    std::cin >> numStr;

    int num = atoiRecursive(numStr);

    std::cout << num << std::endl;
}