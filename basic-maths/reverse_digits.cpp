#include <iostream>

using namespace std;

int main()
{
    int n = 12345;

    int reminder = 0, reverse = 0;

    while (n)
    {
        reminder = n % 10;
        reverse = reverse * 10 + reminder;
        n = n / 10;
    }

    cout << reverse << endl;
}