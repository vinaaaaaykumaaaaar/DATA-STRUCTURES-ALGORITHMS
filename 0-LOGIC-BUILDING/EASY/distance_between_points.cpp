/*
Program to calculate distance between two points
Last Updated : 10 Feb, 2025
You are given two coordinates (x1, y1) and (x2, y2) of a two-dimensional graph. Find the distance between them.

Examples:

Input : x1, y1 = (3, 4)
           x2, y2 = (7, 7)
Output : 5

Input : x1, y1 = (3, 4)
           x2, y2 = (4, 3)
Output : 1.41421
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    float d = 0;

    d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

    cout << d << endl;

    return 0;
}