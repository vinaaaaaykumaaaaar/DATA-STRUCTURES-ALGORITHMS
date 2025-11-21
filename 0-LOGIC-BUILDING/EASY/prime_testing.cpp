/*
Introduction to Primality Test and School Method
Last Updated : 13 Feb, 2025
Given a positive integer, check if the number is prime or not. A prime is a natural number greater than 1 that has no positive divisors other than 1 and itself. Examples of the first few prime numbers are {2, 3, 5, ...}
Examples :

Input:  n = 11
Output: true

Input:  n = 15
Output: false

Input:  n = 1
Output: false
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int flag = 1;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0 && n != i)
        {
            flag = 0;
        }
    }

    if (flag)
        cout << "prime" << endl;
    else
        cout << "not prime" << endl;

    int flag1 = 1;

    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0 && n != i)
        {
            flag1 = 0;
        }
    }
    if (flag1)
        cout << "prime" << endl;
    else
        cout << "not prime" << endl;

    return 0;
}
