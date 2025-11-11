/*
Program for sum of n natural numbers
Last Updated : 04 Sep, 2025
Given a positive integer n, find the sum of the first n natural numbers.

Examples :

Input: n = 3
Output: 6
Explanation: 1 + 2 + 3 = 6

Input: n = 5
Output: 15
Explanation:  1 + 2 + 3 + 4 + 5 = 15
*/

#include <iostream>
using namespace std;

int main()
{
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    cout << sum;
    return 0;
}