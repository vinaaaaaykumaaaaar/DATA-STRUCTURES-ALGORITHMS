#include <iostream>

using namespace std;

class StackArray
{
private:
    static const int MAX_SIZE = 100;
    int stackArray[MAX_SIZE];
    int top; // Index of the top element

public:
    StackArray()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return (top == -1); // Return true if stack is empty
    }

    void push(int element)
    {
        if (top >= MAX_SIZE - 1)
        { // Check if stack is full
            cout << "Stack Overflow!" << endl;
            return;
        }
        stackArray[++top] = element; // Increment top and add the element
        cout << "Pushed " << element << " to stack." << endl;
    }

    int pop()
    {
        if (top < 0)
        { // Check if stack is empty
            cout << "Stack Underflow!" << endl;
            return -1; // Or throw an exception
        }
        return stackArray[top--]; // Return top element and decrement top
    }

    int peek()
    {
        if (top < 0)
        { // Check if stack is empty
            cout << "Stack is empty." << endl;
            return -1; // Or throw an exception
        }
        return stackArray[top]; // Return the top element
    }
    void display()
    {
        if (top < 0)
        {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
        {
            cout << stackArray[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    StackArray stack1;
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);
    stack1.display(); // Output: Stack elements: 30 20 10

    cout << "Top element is: " << stack1.peek() << endl; // Output: Top element is: 30
    cout << "Popped: " << stack1.pop() << endl;          // Output: Popped: 30
    stack1.display();                                    // Output: Stack elements: 20 10

    while (!stack1.isEmpty())
    {
        cout << "Popped: " << stack1.pop() << endl;
    }
    stack1.pop();     // Attempt to pop from an empty stack (Stack Underflow!)
    stack1.display(); // Output: Stack is empty.
    return 0;
}