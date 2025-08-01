// General Algorithm to print all the subsequence elements / power set

#include <iostream>
#include <vector>
#include <string>

void print_resultant_array(std ::vector<int> &resultArray)
{
    for (int i = 0; i < resultArray.size(); i++)
    {
        std::cout << resultArray[i] << " ";
    }
    std::cout << std::endl;
}

void subarray_algorithm(std::vector<int> &array, int index, std::vector<int> &resultArray)
{
    if (index >= array.size())
    {
        print_resultant_array(resultArray);

        return;
    }

    resultArray.push_back(array[index]);
    subarray_algorithm(array, index + 1, resultArray);

    resultArray.pop_back();
    subarray_algorithm(array, index + 1, resultArray);
}

int main()
{
    std::vector<int> a = {1};
    std::vector<int> b = {1, 2};
    std::vector<int> c = {1, 2, 3};

    std::vector<int> result;

    std::vector<std::vector<int>> test_cases = {a, b, c};

    // Dry run test cases
    std::cout << "--------------------- D R Y - R U N ---------------------" << std::endl;
    for (auto test_case : test_cases)
    {
        subarray_algorithm(test_case, 0, result);
        std::cout << "-----------------------------------------------------------------" << std::endl;
    }

    return 0;
}