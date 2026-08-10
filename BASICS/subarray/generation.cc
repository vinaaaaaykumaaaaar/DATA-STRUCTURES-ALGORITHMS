#include <iostream>
#include <vector>

int main()
{
    std::vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();

    std::cout << "All Subarrays " << std::endl;

    for (int start = 0; start < arr.size(); start++)
    {
        for (int end = start; end < arr.size(); end++)
        {
            std::cout << "[ ";
            for (int i = start; i <= end; i++)
            {
                std::cout << arr[i] << " ";
            }

            std::cout << "]" << std::endl;
        }
    }

    return 0;
}