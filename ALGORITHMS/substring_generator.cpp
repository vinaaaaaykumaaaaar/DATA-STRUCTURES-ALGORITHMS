// Algorithm to generate all the substring in the string

#include <iostream>
#include <vector>
#include <string>

void print_resultant_string(std ::string &result_string)
{
    std::cout << result_string << std::endl;
    return;
}

void substring_algorithm(std::string &base_string, int index, std::string &result_string)
{
    if (index >= base_string.length())
    {
        print_resultant_string(result_string);
        return;
    }

    result_string += base_string[index];
    substring_algorithm(base_string, index + 1, result_string);

    result_string.pop_back();
    substring_algorithm(base_string, index + 1, result_string);
}

int main()
{
    std::string a = "a";
    std::string b = "ab";
    std::string c = "abc";

    std::string result = "";

    std::vector<std::string> test_cases = {a, b, c};

    // Dry run test cases
    std::cout << "--------------------- D R Y - R U N ---------------------" << std::endl;
    for (auto test_case : test_cases)
    {
        substring_algorithm(test_case, 0, result);
        std::cout << "-----------------------------------------------------------------" << std::endl;
    }

    return 0;
}