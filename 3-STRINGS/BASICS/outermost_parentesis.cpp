#include <iostream>
#include <vector>
#include <utility>
#include <type_traits>
#include <string>
#include <algorithm>
#include <array>

using namespace std;

int main()
{
    string s = "(()())(())()";

    string res;

    long long count = 0;
    for (char c : s)
    {
        if (c == '(' && count++ > 0)
            res += c;

        else if (c == ')' && count-- > 1)
            res += c;
    }

    cout << res;
}