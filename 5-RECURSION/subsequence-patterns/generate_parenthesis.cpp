/*
Given an integer n.Generate all possible combinations of well-formed parentheses of length 2 x N.


Examples:
Input : n = 3

Output : [ "((()))" , "(()())" , "(())()" , "()(())" , "()()()" ]

Input : 2

Output : [ "(())" , "()()" ]
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generateParentheses(string &s, int open, int close)
{
    if (open == 0 && close == 0)
    {
        cout << s << endl;
        return;
    }

    if (open > 0)
    {
        s.push_back('(');
        generateParentheses(s, open - 1, close);
        s.pop_back();
    }

    if (close > 0)
    {
        if (open < close)
        {
            s.push_back(')');
            generateParentheses(s, open, close - 1);
            s.pop_back();
        }
    }
}

int main()
{
    int n = 3;
    string s = "";

    generateParentheses(s, n, n);

    return 0;
}
