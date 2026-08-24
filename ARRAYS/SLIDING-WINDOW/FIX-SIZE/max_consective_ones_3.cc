#include <iostream>
#include <vector>

using namespace std;

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

    return 0;
}