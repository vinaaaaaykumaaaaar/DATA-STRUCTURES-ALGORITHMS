#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    vector<int> arr = {10, 5, 10, 15, 10, 5};

    map<int, int> hash;

    for (auto a : arr)
        hash[a]++;

    int highest = -1, lowest = 1000000, highest_element = 0, lowest_element = 0;

    for (auto h : hash)
    {
        if (h.second > highest)
        {
            highest_element = h.first;
            highest = h.second;
        }
        if (h.second < lowest)
        {
            lowest_element = h.first;
            lowest = h.second;
        }
    }

    cout << highest << " " << highest_element << endl;
    cout << lowest << " " << lowest_element << endl;

    return 0;
}