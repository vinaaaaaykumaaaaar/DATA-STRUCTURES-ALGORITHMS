/*

Sort a Stack using Recursion

Given a stack, the task is to sort it using recursion.

Example:

Input: [3 2 1]
Output: [3 2 1]
Explanation: The given stack is sorted know 3 > 2 > 1

Input: [11 2 32 3 41]
Output: [41 32 11 3 2]

*/

#include <iostream>
#include <stack>

using namespace std;

void sortInsert(stack<int> &s, int x)
{
    if (s.empty() || s.top() < x)
    {
        s.push(x);

        return;
    }

    int temp = s.top();
    s.pop();
    sortInsert(s, x);
    s.push(temp);
}

void sort(stack<int> &s)
{

    if (!s.empty())
    {
        int x = s.top();
        s.pop();
        sort(s);
        sortInsert(s, x);
    }
}

int main()
{
    stack<int> s;
    s.push(11);
    s.push(2);
    s.push(32);
    s.push(3);
    s.push(41);

    sort(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
