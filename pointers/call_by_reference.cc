#include <iostream>
using namespace std;

void increment(int &a)
{
    a = a + 1;
}

int main()
{
    int a = 10;
    cout << "Before function call a : " << a << endl;
    increment(a);
    cout << "After function call a : " << a << endl;

    return 0;
}