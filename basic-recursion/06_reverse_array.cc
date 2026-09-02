#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> reverse_array(vector<int> &arr, int inital_point, int end_point)
{
    if (inital_point >= end_point)
        return arr;

    swap(arr[inital_point], arr[end_point]);
    return reverse_array(arr, inital_point + 1, end_point - 1);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    vector<int> reversed_array = reverse_array(arr, 0, arr.size() - 1);

    for (auto element : reversed_array)
        cout << element << " ";
    cout << endl;

    return 0;
}