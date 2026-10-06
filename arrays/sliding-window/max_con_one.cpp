#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int brute_force(vector<int> &arr)
{
    int count = 0;
    int maxCount = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 1)
        {
            count = 0;
            continue;
        }

        count++;
        maxCount = max(maxCount, count);
    }

    return maxCount;
}

int main()
{
    vector<int> arr = {1, 0, 1, 1, 0, 1};

    cout << brute_force(arr) << endl;

    return 0;
}