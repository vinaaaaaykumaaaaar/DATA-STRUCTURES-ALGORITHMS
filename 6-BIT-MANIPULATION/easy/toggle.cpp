#include <iostream>
using namespace std;

int main()
{
    int i, x = 1;
    cin >> i;
    int res = (x ^ (1 << i));

    cout << res << endl;
}