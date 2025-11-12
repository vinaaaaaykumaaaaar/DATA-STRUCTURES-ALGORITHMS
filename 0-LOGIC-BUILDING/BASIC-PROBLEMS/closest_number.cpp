/*
Find Closest to n and Divisible by m
Last Updated : 09 Jul, 2025
Given two integers n and m (m != 0). Find the number closest to n and divisible by m. If there is more than one such number, then output the one having maximum absolute value.

Examples:

Input: n = 13, m = 4
Output: 12
Explanation: 12 is the closest to 13, divisible by 4.

Input: n = -15, m = 6
Output: -18
Explanation: Both -12 and -18 are closest to -15, but -18 has the maximum absolute value.
*/

#include <iostream>
#include <climits>
using namespace std;

int closestNumber(int n, int m)
{

    int closest = 0;
    int minDifference = INT_MAX;

    // Check numbers around n
    for (int i = n - abs(m); i <= n + abs(m); ++i)
    {
        if (i % m == 0)
        {
            int difference = abs(n - i);

            if (difference < minDifference ||
                (difference == minDifference && abs(i) > abs(closest)))
            {
                closest = i;
                minDifference = difference;
            }
        }
    }
    return closest;
}

int main()
{
    int n = -15, m = 6;
    cout << closestNumber(n, m) << endl;

    return 0;
}