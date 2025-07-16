#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> arr = {10, 22, 12, 3, 0, 6};
    vector<int> res;

    // for (int i = 0; i < arr.size(); ++i)
    // {
    //     for (int j = i + 1; j < arr.size(); ++j)
    //     {
    //         if (arr[j] > arr[i])
    //         {
    //             break;
    //         }

    //         if (j == arr.size() - 1)
    //         {
    //             res.push_back(arr[i]);
    //         }
    //     }

    //     if (i == arr.size() - 1)
    //     {
    //         res.push_back(arr[i]);
    //     }
    // }

    res.push_back(arr[arr.size() - 1]);

    for (int i = arr.size() - 2; i >= 0; i--)
    {
        if (arr[i] > res[res.size() - 1])
        {
            res.push_back(arr[i]);
        }
    }

    for (auto x : res)
        cout << x << " ";
    cout << endl;

    return 0;
}