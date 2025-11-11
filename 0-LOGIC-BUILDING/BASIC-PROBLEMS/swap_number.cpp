/*
Swap Two Numbers
Last Updated : 23 Jul, 2025
Given two numbers a and b, the task is to swap them.

Examples:

Input: a = 2, b = 3
Output: a = 3, b = 2

Input: a = 20, b = 0
Output: a = 0, b = 20

Input: a = 10, b = 10
Output: a = 10, b = 10

*/

#include <iostream>
using namespace std;

// time complexity -> O(1)
//  space complexity -> O(1)
void brute_force(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout << a << " " << b << endl;
}

void better_solution(int a, int b)
{
    a = a + b; // a becomes sum of a and b
    b = a - b; // b becomes original a
    a = a - b; // a becomes original b

    cout << a << " " << b << endl;
}

int main()
{
    int a, b;
    cin >> a >> b;
    brute_force(a, b);
    better_solution(a, b);
    return 0;
}