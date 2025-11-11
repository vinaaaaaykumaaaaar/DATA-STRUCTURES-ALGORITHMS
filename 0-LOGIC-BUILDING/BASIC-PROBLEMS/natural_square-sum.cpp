/*

Program for Sum of squares of first n natural numbers
Last Updated : 29 Mar, 2025
Given a positive integer n, we have to find the sum of squares of first n natural numbers.
Examples :

Input : n = 2
Output: 5
Explanation: 1^2+2^2 = 5

Input : n = 8
Output: 204
Explanation :  1^2 + 2^2 + 3^2 + 4^2 + 5^2 + 6^2 + 7^2 + 8^2 = 204
*/

#include <iostream>
using namespace std;

// time complexity -> O(n)
// space complexity -> O(1)
int brute_force(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += (i * i);
    }

    return sum;
}

// time complexity -> O(1)
// space complexity -> O(1)
int better_sol(int n)
{

    int sum = (n * (n + 1) * (2 * n + 1)) / 6;
    return sum;
}

int main()
{

    int n;
    cin >> n;
    cout << brute_force(n) << endl;
    cout << better_sol(n) << endl;
}