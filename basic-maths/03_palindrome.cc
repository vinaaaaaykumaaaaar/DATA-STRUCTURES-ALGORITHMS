#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int duplicate = n, rev = 0, rem = 0;

    while (duplicate > 0)
    {
        cout << rev << " " << rem << " " << duplicate << endl;
        rem = duplicate % 10;
        rev = rev * 10 + rem;
        duplicate = duplicate / 10;
    }

    if (rev == n)
        cout << "palindrome" << endl;
    else
        cout << "not a palindrome" << endl;
}