#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {10, 5, 10, 15, 10, 5};

    unordered_map<int, int> frequency;

    for (auto x : arr)
    {
        frequency[x]++;
    }

    for (auto x : frequency)
    {
        cout << x.first << " frequency is " << x.second << endl;
    }

    return 0;
}