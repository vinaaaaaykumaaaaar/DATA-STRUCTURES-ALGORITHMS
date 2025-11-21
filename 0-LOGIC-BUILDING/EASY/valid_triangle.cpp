/*
Check whether triangle is valid or not if sides are given
Last Updated : 10 Feb, 2025
Given three sides, check whether triangle is valid or not.

Examples:

Input :  a = 7, b = 10, c = 5
Output : Valid
We can draw a triangle with the given three edge lengths.

Input : a = 1, b = 10, c = 12
Output : Invalid
We can not draw a triangle with the given three edge lengths.

*/

#include <iostream>
using namespace std;

int main()
{

    int a, b, c;
    cin >> a >> b >> c;

    if ((a + b > c) && (b + c > a) && (c + a > b))
    {
        cout << "valid" << endl;
    }
    else
    {
        cout << "not valid" << endl;
    }
    return 0;
}