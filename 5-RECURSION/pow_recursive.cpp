#include <iostream>
using namespace std;

double pow(double x, int p)
{
    if (p < 1)
        return 1;
    return x * pow(x, p - 1);
}
int main()
{
    double x = 2.1;
    int p = 3;

    cout << pow(x, p);
}