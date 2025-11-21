/*
Factorial of a Number
Last Updated : 03 Oct, 2025
Given the non-negative integers n , compute the factorial of a given number.
Note: Factorial of n is defined as n * (n -1) * (n - 2) * ... * 1, for n = 0, factorial is 1.

Examples:

Input: n = 5
Output: 120
Explanation: 5! = 5 * 4 * 3 * 2 * 1 = 120

Input: n = 4
Output: 24
Explanation: 4! = 4 * 3 * 2 * 1 = 24
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int fact = 1;
    while (n)
    {
        fact *= n;
        n--;
    }

    cout << "factorial = " << fact << endl;

    return 0;
}