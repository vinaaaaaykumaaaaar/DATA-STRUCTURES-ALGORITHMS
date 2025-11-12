/*
Write a program to reverse digits of a number
Last Updated : 21 May, 2025
Given an Integer n, find the reverse of its digits.

Examples:

Input: n = 122
Output: 221
Explanation: By reversing the digits of number, number will change into 221.

Input: n = 200
Output: 2
Explanation: By reversing the digits of number, number will change into 2.

Input: n = 12345
Output: 54321
Explanation: By reversing the digits of number, number will change into 54321.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string Nstring = to_string(n);

    int reverse = 0;

    while (n)
    {
        int temp = n % 10;
        reverse = (reverse * 10) + temp;
        n = n / 10;
    }

    cout << reverse << endl;

    int i = 0, j = Nstring.length() - 1;

    while (i < j)
    {
        swap(Nstring[i], Nstring[j]);
        i++, j--;
    }

    cout << Nstring << endl;

    return 0;
}