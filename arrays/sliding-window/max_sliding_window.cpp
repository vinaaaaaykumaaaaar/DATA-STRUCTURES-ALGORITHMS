#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> brute_force(vector<int> &arr, int k)
{

    int n = arr.size();
    vector<int> result;

    for (int i = 0; i <= n - k; i++)
    {
        int maxNumber = INT_MIN;
        for (int j = i; j < i + k; j++)
        {
            maxNumber = max(maxNumber, arr[j]);
        }

        result.push_back(maxNumber);
    }

    return result;
}

int main()
{
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};

    int k = 3;

    vector<int> res = brute_force(arr, k);

    for (auto x : res)
        cout << x << " ";
    cout << endl;

    return 0;
}