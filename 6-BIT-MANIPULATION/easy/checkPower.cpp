#include <iostream>
using namespace std;

int main()
{
    int x = 3;
    int res = ((x & (x - 1)) == 0);
    if (res)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}