#include <iostream>
using namespace std;

#define Max 300

class Stack
{
private:
    int arr[Max];
    int top;

public:
    Stack() { top = -1; }

    int size()
    {
        return top;
    }

    void push(int x)
    {
        if (top >= Max)
        {
            cout << "stack is full" << endl;
            return;
        }
        arr[++top] = x;
    }

    int pop()
    {
        if (top < 0)
        {
            cout << "Stack underflow" << endl;
        }
        return arr[top--];
    }

    int peek()
    {
        if (top < 0)
        {
            cout << "stack underflow" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.display();
}