/*

------------------ Bubble Sort -----------------

key word --> adjacent swap

*/

#include <iostream>
using namespace std;

int main()
{
    int arr[6] = {13, 24, 46, 20, 9, 52};

    for (int i = 5; i >= 0; i++)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << endl;
    }
}