#include <iostream>

using namespace std;

int main()
{
    int num = 120;

    int reverse = 0, temp = 0, copy = num;

    while (num)
    {
        temp = num % 10;
        reverse = reverse * 10 + temp;
        num = num / 10;
    }

    if (copy == reverse)
        cout << "Palindrome" << endl;
    else
        cout << "Not a Palindrome" << endl;

    return 0;
}