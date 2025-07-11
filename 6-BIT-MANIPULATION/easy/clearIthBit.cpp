#include <iostream>
using namespace std;

int main()
{
    int x = 8;
    int y;
    cin >> y;

    int init = ~(1 << y);

    int res = (x & init);

    cout << res << endl;
}