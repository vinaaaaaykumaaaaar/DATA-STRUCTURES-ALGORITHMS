#include <iostream>
using namespace std;

int main()
{
    int n = 4124;
    int original = n;
    int temp = 0;

    while (n)
    {
        temp = temp * 10 + (n % 10);
        n = n / 10;
    }

    if (temp == original)
    {
        cout << "palindrome" << endl;
    }
    else
    {
        cout << "not a palindrome" << endl;
    }

    return 0;
}