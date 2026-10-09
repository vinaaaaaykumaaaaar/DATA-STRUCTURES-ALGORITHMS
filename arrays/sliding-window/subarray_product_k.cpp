#include <iostream>
#include <vector>
using namespace std;

int brute_force(vector<int> &arr, int target)
{
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {

        int product = 1;
        for (int j = i; j < n; j++)
        {

            product *= arr[j];

            if (product >= target)
                break;
            count++;
            cout << product << " " << count << " ";
        }
        cout << endl;
    }

    return count;
}

int better_solution(vector<int> &arr, int target)
{
    int l = 0;
    int count = 0;
    int product = 1;
    for (int r = 0; r < arr.size(); ++r)
    {
        product *= arr[r];

        while (product >= target && l <= r)
        {
            product /= arr[l];
            l++;
        }

        count += (r - l + 1);
    }

    return count;
}

int main()
{
    vector<int> arr = {10, 5, 2, 6};
    int k = 100;

    // cout << brute_force(arr, k) << endl;
    cout << better_solution(arr, k) << endl;
}