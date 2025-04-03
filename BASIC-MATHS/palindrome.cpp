#include <iostream>
using namespace std;

int main()
{
    string s, copy;
    cin >> s;
    copy = s;

    int i = 0, j = s.size() - 1;

    while (i < j)
    {
        swap(copy[i], copy[j]);
        j--, i++;
    }

    if (s == copy)
        cout << "Palindrome" << endl;
    else
        cout << "Not a palindrome" << endl;
}