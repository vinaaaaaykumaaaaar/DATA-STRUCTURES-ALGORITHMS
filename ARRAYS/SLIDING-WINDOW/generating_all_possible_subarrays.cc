#include <iostream>
#include <vector>
using namespace std;

void generate_all_subarrays(vector<int> arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cout << "[";
            for (int k = i; k <= j; k++)
            {
                cout << arr[k];
                if (k < j)
                    cout << ", ";
            }
            cout << "]" << endl;
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 3};

    generate_all_subarrays(arr);

    return 0;
}