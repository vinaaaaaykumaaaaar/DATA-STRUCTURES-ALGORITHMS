#include <iostream>
#include <vector>

using namespace std;

void reverse_array(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;

    swap(arr[start], arr[end]);

    reverse_array(arr, start + 1, end - 1);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    reverse_array(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++)
    {
        /* code */
        cout << arr[i] << " ";
    }

    cout << endl;
}