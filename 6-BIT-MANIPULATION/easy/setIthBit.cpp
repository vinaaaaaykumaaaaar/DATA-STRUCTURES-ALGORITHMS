#include <iostream>

using namespace std;

int main()
{
    int x = 1;
    int i;
    cin >> i;
    int res = (x | (1 << i));
    cout << res << endl;
}