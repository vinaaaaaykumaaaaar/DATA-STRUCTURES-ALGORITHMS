#include <iostream>

using namespace std;

int main()
{
    int x = 10, y = 20;

    x = x ^ y;
    y = x ^ y;
    x = x ^ y;

    cout << "x = " << x << " y = " << y << endl;
    return 0;
}