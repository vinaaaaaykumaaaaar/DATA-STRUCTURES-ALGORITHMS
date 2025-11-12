/*
The dice problem
Last Updated : 16 Jul, 2025
You are given a cubic dice with 6 faces. All the individual faces have a number printed on them. The numbers are in the range of 1 to 6, like any ordinary dice. You will be provided with a face of this cube, your task is to guess the number on the opposite face of the cube.

Examples:

Input: n = 2
Output: 5
Explanation: For dice facing number 5 opposite face will have the number 2.

Input: n = 6
Output: 1
Explanation: For dice facing number 6 opposite face will have the number 1.

*/

#include <iostream>

using namespace std;

// time complexity -> O(1)
// space complexity -> O(1)
int brute_force(int n)
{
    int number;

    if (n == 1)
    {
        number = 6;
    }
    else if (n == 2)
    {
        number = 5;
    }
    else if (n == 3)
    {
        number = 4;
    }
    else if (n == 4)
    {
        number = 3;
    }
    else if (n == 5)
    {
        number = 2;
    }
    else
    {
        number = 1;
    }

    return number;
}

// time complexity -> O(1)
// space complexity -> O(1)
int optimal_solution(int n)
{
    return 7 - n;
}

int main()
{

    int n;
    cin >> n;
    cout << brute_force(n) << endl;
    cout << optimal_solution(n) << endl;
    return 0;
}