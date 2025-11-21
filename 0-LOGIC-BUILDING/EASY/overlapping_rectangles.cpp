/*
Find if two rectangles overlap
Last Updated : 11 Sep, 2025
Given two rectangles, find if the given two rectangles overlap or not.
Note that a rectangle can be represented by two coordinates, top left and bottom right. So mainly we are given following four coordinates.
l1: Top Left coordinate of first rectangle.
r1: Bottom Right coordinate of first rectangle.
l2: Top Left coordinate of second rectangle.
r2: Bottom Right coordinate of second rectangle.

Input: l1 = { 0, 10 }, r1 = { 10, 0 }, l2 = { 5, 5 }, r2 = { 15, 0 }
Output: Rectangles Overlap

Input: l1 = { 0, 10 }, r1 = { 10, 0 }, l2 = { -10, 5 }, r2 = { -1, 0 }
Output: Rectangles Don't Overlap
*/

#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};

int main()
{
    Point l1 = {0, 10}, r1 = {10, 0};
    Point l2 = {5, 5}, r2 = {15, 0};

    if (l1.x > r1.x || l2.x > r1.x)
    {
        cout << "Rectangles donot overlap " << endl;
    }
    else if (r1.y > l1.y || r2.y > l2.y)
    {
        cout << "Rectangles donot overlap " << endl;
    }
    else
    {
        cout << "Rectangles overlap" << endl;
    }

    return 0;
}
