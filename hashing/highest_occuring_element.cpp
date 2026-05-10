/*
Find the highest/lowest frequency element

Problem Statement: Given an array of size N. Find the highest and lowest frequency element.

Examples
Example 1:
Input: array[] = {10,5,10,15,10,5};
Output: 10 15
Explanation: The frequency of 10 is 3, i.e. the highest and the frequency of 15 is 1 i.e. the lowest.


Example 2:
Input: array[] = {2,2,3,4,4,2};
Output: 2 3
Explanation: The frequency of 2 is 3, i.e. the highest and the frequency of 3 is 1 i.e. the lowest.
*/

#include <iostream>
#include <unordered_map>
#include <vector>

// Base case: no arguments
void _debug_print()
{
    std::cerr << std::endl;
}

// Single argument (any type)
template <typename T>
void _debug_print(const T &t)
{
    std::cerr << t;
}

// Special case: nice printing for std::vector (works recursively!)
template <typename T>
void _debug_print(const std::vector<T> &v)
{
    std::cerr << "[";
    for (size_t i = 0; i < v.size(); ++i)
    {
        _debug_print(v[i]);
        if (i + 1 < v.size())
            std::cerr << ", ";
    }
    std::cerr << "]";
}

// Variadic (multiple arguments)
template <typename T, typename... Args>
void _debug_print(const T &t, Args &&...args)
{
    _debug_print(t);
    std::cerr << " ";
    _debug_print(std::forward<Args>(args)...);
}

// ==================== THE MAGIC DEBUG MACRO ====================

#define debug(...)                                  \
    do                                              \
    {                                               \
        std::cerr << "[" << #__VA_ARGS__ << "] = "; \
        _debug_print(__VA_ARGS__);                  \
        std::cerr << std::endl;                     \
    } while (0)

using namespace std;

int main()
{
    vector<int> input_data = {10, 5, 10, 15, 10, 5};

    unordered_map<int, int> hash_table;

    for (int i = 0; i < input_data.size(); i++)
    {
        hash_table[input_data[i]]++;
    }

    int maxFreq = 0, minFreq = input_data.size();
    int maxEle = 0, minEle = 0;

    // Traverse the map to find elements with max and min frequencies
    for (auto it : hash_table)
    {
        int element = it.first;
        int count = it.second;

        // Update max frequency element
        if (count > maxFreq)
        {
            maxFreq = count;
            maxEle = element;
        }

        // Update min frequency element
        if (count < minFreq)
        {
            minFreq = count;
            minEle = element;
        }
    }

    // Print results
    cout << "The highest frequency element is: " << maxEle << "\n";
    cout << "The lowest frequency element is: " << minEle << "\n";
}