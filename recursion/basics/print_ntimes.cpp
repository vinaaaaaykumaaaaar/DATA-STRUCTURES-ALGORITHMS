#include <iostream>

using namespace std;

void print_1_n(int i, int n)
{
    if (i > n)
        return;

    cout << i << endl;
    print_1_n(i + 1, n);
}

int main()
{

    print_1_n(1, 10);

    return 0;
}