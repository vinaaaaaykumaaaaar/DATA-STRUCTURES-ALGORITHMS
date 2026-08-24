#include <iostream>
#include <vector>
using namespace std;

int max_consective(vector<int> &arr)
{
    int n = arr.size();
    int max_count = 0;

    int i = 0;
    while (i < n)
    {
        if (arr[i] == 0)
        {
            i++;
            continue;
        }

        int j = i;
        int count = 0;
        while (j < n && arr[j] == 1)
        {
            count++;
            j++;
        }

        max_count = max(max_count, count);
        i = j;
    }

    return max_count;
}

int sliding_window(vector<int> arr)
{
    int n = arr.size();
    int max_ones = 0;
    int l = 0;

    for (int r = 0; r < n; r++)
    {
        if (arr[r] == 0)
        {
            l = r + 1;
        }
        else
        {
            max_ones = max(max_ones, r - l + 1);
        }
    }

    return max_ones;
}

int main()
{
    vector<int> arr = {1, 1, 1, 1, 0, 1, 1, 1};

    cout << sliding_window(arr) << endl;

    return 0;
}