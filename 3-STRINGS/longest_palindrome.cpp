#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <list>

using namespace std;

bool isPalindrome(string s)
{
    int l = 0;
    int r = s.length() - 1;

    while (l < r)
    {
        if (s[l] != s[r])
        {
            return false;
        }
        ++l;
        --r;
    }

    return true;
}

string solve(string &s)
{

    if (s.length() <= 1)
        return s;

    int m = 1;
    string ms = s.substr(0, 1);

    for (int i = 0; i < s.length(); ++i)
    {
        for (int j = i + m; j <= s.length(); ++j)
        {
            if (j - i > m && isPalindrome(s.substr(i, j - i)))
            {
                m = j - i;
                ms = s.substr(i, j - 1);
            }
        }
    }

    return ms;
}

int main()
{

    string s = "babad";

    cout << solve(s) << endl;
    return 0;
}