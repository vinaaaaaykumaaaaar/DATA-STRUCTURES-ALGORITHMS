#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            int top = i, left = j, right = 6 - j, bottom = 6 - i;
            cout << (4 - min(min(top, bottom), min(left, right)));
        }
        cout << endl;
    }
}