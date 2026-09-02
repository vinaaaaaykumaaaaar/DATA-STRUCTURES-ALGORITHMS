#include <iostream>
#include <string>
using namespace std;

void print_name(int n, string name)
{
    if (n <= 0)
        return;

    cout << name << "\n";
    print_name(n--, name);
}

int main()
{
    int n;
    string name;

    cin >> n >> name;

    print_name(n, name);

    return 0;
}