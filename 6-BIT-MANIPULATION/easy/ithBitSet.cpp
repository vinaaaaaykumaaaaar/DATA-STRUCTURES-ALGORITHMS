#include <iostream>

using namespace std;

int main()
{
    int x = 13;
    int i;
    cin >> i;
    int res = (x & (1 << i)) == 0;
    cout << res << endl;
}