/*
Generate all the binary strings of N bits
Given a positive integer number N. The task is to generate all the binary strings of N bits.
These binary strings should be in ascending order.
Examples:

Input: 2
Output:
0 0
0 1
1 0
1 1
Input: 3
Output:
0 0 0
0 0 1
0 1 0
0 1 1
1 0 0
1 0 1
1 1 0
1 1 1
*/

#include <iostream>
#include <string>

using namespace std;

void print(string &s, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << s[i];
    }
    cout << endl;
}

void generate_binary_strings(int n, string &s, int i)
{
    if (i == n)
    {
        print(s, n);
        return;
    }

    s[i] = '0';
    generate_binary_strings(n, s, i + 1);

    s[i] = '1';
    generate_binary_strings(n, s, i + 1);
}

int main()
{
    int n = 5;
    string s;

    generate_binary_strings(n, s, 0);

    return 0;
}