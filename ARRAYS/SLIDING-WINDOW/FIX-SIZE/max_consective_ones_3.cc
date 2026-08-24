#include <iostream>
#include <vector>

using namespace std;

int sliding_window(vector<int> &arr, int k)
{
    int n = arr.size();
    int left = 0;
    int max_count = 0;
    int kz = 0; // zero count

    for (int right = 0; right < n; right++)
    {
        if (arr[right] == 0)
            kz++;

        while (kz > k)
        {
            if (arr[left] == 0)
                kz--;
            left++;
        }

        max_count = max(max_count, right - left + 1);
    }

    return max_count;
}

int main()
{
    vector<int> arr = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};

    int n = arr.size();

    int k = 2;
    int max_count = 0;

    for (int i = 0; i < n; i++)
    {
        int kz = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[j] == 0)
                kz++;
            if (kz <= k)
            {
                max_count = max(max_count, j - i + 1);
            }
        }
    }

    cout << max_count << endl;
    cout << "\n\n";

    cout << sliding_window(arr, k) << endl;

    return 0;
}