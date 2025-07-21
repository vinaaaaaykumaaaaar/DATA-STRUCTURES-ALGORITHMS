#include <iostream>

using namespace std;

int maxDepth(string s)
{
    int r = 0, c = 0;
    for (char &i : s)
    {
        if (i == '(')
            r = max(r, ++c);
        if (i == ')')
            --c;
    }

    return r;
}

int main()
{
    string s = "(1+(2+3)+((8)/4))+1";
    cout << maxDepth(s) << endl;

    return 0;
}