/*
Sum of Digits of a Number
Last Updated : 14 Jul, 2025
Given a number n, find the sum of its digits.

Examples :

Input: n = 687
Output: 21
Explanation: The sum of its digits are: 6 + 8 + 7 = 21

Input: n = 12
Output: 3
Explanation: The sum of its digits are: 1 + 2 = 3
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{

    int n;
    cin >> n;
    string sNumber = to_string(n);

    int sum = 0;
    while (n)
    {
        int temp = n % 10;
        sum += temp;
        n = n / 10;
    }

    cout << sum << endl;

    int sSum = 0;
    for (int i = 0; i < sNumber.size(); i++)
    {
        sSum += sNumber[i] - '0';
    }

    cout << sSum << endl;
}