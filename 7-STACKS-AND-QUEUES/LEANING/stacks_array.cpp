#include <iostream>

using namespace std;

class Stack
{

public:
    int size;
    int *a;
    int top;

public:
    Stack()
    {
        top = -1;
        size = 1000;
        a = new int[size];
    }

    void push(int x)
    {
        top++;
        a[top] = x;
    }
    int pop()
    {
        int x = a[top];
        top--;
        return x;
    }

    int Top()
    {
        return a[top];
    }
    int Size()
    {
        return top + 1;
    }
};

int main()
{
    Stack s;
    cout << s.Size();
    s.push(10);
    s.push(20);

    cout << s.Size();


    cout << s.Top();
    return 0;
}