/*

How to Reverse a Stack using Recursion

Write a program to reverse a stack using recursion, without using any loop.

Example:

Input: elements present in stack from top to bottom 4 3 2 1
Output: 1 2 3 4

Input: elements present in stack from top to bottom 1 2 3
Output: 3 2 1

*/

#include <iostream>
#include <stack>
using namespace std;

void insert(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int temp = s.top();
    s.pop();
    insert(s, x);
    s.push(temp);
}

void reverse_stack(stack<int> &s)
{
    if (!s.empty())
    {
        int x = s.top();
        s.pop();
        reverse_stack(s);
        insert(s, x);
    }
}

int main()
{
    stack<int> s;

    // Pushing elements to the stack: 4 3 2 1 (bottom to top)
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    // Reversing the stack
    // reverse_stack(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}