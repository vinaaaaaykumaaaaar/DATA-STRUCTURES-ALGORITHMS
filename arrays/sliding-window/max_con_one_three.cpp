#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int brute_force(vector<int> &arr, int k)
{

    int maxCount = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int zeroCount = 0;
        for (int j = i; j < arr.size(); j++)
        {

            if (arr[j] == 0)
                zeroCount++;
            if (zeroCount > k)
                break;
            maxCount = max(maxCount, j - i + 1);
        }
    }

    return maxCount;
}

int main()
{
    vector<int> arr = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k = 3;

    cout << brute_force(arr, k) << endl;

    return 0;
}