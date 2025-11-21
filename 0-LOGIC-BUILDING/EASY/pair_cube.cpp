/*
Pair Cube Count
Last Updated : 19 Mar, 2025
Given n, count all 'a' and 'b' that satisfy the condition a^3 + b^3 = n. Where (a, b) and (b, a) are considered two different pairs

Examples:

Input: n = 9
Output: 2
Explanation: 1^3 + 2^3 = 9 and 2^3 + 1^3 = 9

Input: n = 28
Output: 2
Explanation: 1^3 + 3^3 = 28 and 3^3 + 1^3 = 28
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 0;

    for (int a = 0; a <= n; a++)
    {
        for (int b = 0; b <= n; b++)
        {
            if (a * a * a + b * b * b == n)
            {
                count++;
            }
        }
    }

    cout << count << endl;
}