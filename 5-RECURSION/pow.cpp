#include <iostream>

using namespace std;

int main()
{

    double x = 2.1, p = 3.0;
    double ans = 1.0;
    for (int i = 0; i < p; i++)
    {

        ans *= x;
    }

    cout << ans;
    return 0;
}