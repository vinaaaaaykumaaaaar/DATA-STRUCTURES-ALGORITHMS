#include <iostream>
using namespace std;

int main()
{
    int x = 9;

    int res = (x & (x - 1));
    cout << res << endl;
}