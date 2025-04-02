#include <iostream>
using namespace std;

// selection sort -> select minimum in the array at every iteration

int main()
{
    int a[6] = {13, 46, 24, 52, 20, 9};

    for (int i = 0; i < 6; i++)
    {

        for (int j = i; j < 6; j++)
        {
            if (a[j] < a[i])
            {
                swap(a[i], a[j]);
            }
        }
    }

    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}