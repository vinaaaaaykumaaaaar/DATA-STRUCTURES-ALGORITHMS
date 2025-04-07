#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<int, 6> a = {3, 2, 1, 5, 2};

    int largest = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > largest)
            largest = a[i];
    }

    cout << "Largest " << largest << endl;
    return 0;
}