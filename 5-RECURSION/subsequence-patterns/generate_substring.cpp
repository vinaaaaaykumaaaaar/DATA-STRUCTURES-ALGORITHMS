/*

Power Set: Print all the possible subsequences of the String

Problem Statement: Given a string, find all the possible subsequences of the string.

Examples:

Example 1:
Input: str = "abc"
Output: a ab abc ac b bc c
Explanation: Printing all the 7 subsequence for the string "abc".

Example 2:
Input: str = "aa"
Output: a a aa
Explanation: Printing all the 3 subsequences for the string "aa"

*/

#include <bits/stdc++.h>

using namespace std;

void generate(string &s, vector<string> &v, int i, string &s1)
{
    if (i == s.length())
    {
        cout << s1 << endl;
        v.push_back(s1);

        return;
    }

    s1.push_back(s[i]);
    generate(s, v, i + 1, s1);

    s1.pop_back();
    generate(s, v, i + 1, s1);
}

int main()
{

    string s = "abc";

    vector<string> v;
    string s1 = "";

    generate(s, v, 0, s1);
}