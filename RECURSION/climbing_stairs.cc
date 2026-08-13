#include <iostream>
using namespace std;

int recursion(int n)
{
    if (n < 3)
        return n;

    return recursion(n - 1) + recursion(n - 2);
}

int main()
{
    int n;
    cin >> n;

    cout << recursion(n) << endl;
}