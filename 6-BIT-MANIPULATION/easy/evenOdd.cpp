#include <iostream>
using namespace std;

// the last bit of the odd number is always 1
// the last bit of the even number is  always 0

// the & operator says the number is odd or not
int main()
{

    int n = 11;

    if ((n & 1) == 0)
        cout << "Even Number" << endl;
    else
        cout << "Odd Number" << endl;

    return 0;
}