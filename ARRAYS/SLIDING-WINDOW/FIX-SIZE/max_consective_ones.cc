#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {1, 1, 0, 1, 1, 1};

    int max_ones = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int count = 0;

        for (int j = i; j < arr.size(); j++)
        {
            if (arr[j] == 0)
                break;

            count++;
        }

        max_ones = max(max_ones, count);
    }

    cout << max_ones << endl;

    return 0;
}