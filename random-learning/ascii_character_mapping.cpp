#include <iostream>
#include <string>

using namespace std;

int main()
{
    string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lowercase = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < uppercase.length(); i++)
    {
        cout << uppercase[i] << " = " << uppercase[i] - 0 << endl;
    }

    cout << endl;

    for (int i = 0; i < lowercase.length(); i++)
    {
        cout << lowercase[i] << " = " << lowercase[i] - 0 << endl;
    }

    cout << endl;
}