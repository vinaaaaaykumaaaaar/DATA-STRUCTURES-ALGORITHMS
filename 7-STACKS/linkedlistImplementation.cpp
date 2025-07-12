#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack
{
private:
    Node *head;

public:
    Stack()
    {
        head = nullptr;
    }

    void push(int element)
    {
        Node *newNode = new Node(element);
        if (newNode == nullptr)
        { // Check for memory allocation failure
            cout << "Stack Overflow (Memory Allocation Failed)!" << endl;
            return;
        }
        newNode->next = head; // New node points to the current head
        head = newNode;       // New node becomes the new head
        cout << "Pushed " << element << " to stack." << endl;
    }

    int pop()
    {

        if (head == nullptr)
        { // Check if stack is empty
            cout << "Stack Underflow!" << endl;
            return -1; // Or throw an exception
        }
        int poppedValue = head->data;
        Node *temp = head;
        head = head->next; // Move head to the next node
        delete temp;       // Free memory of the removed node
        return poppedValue;
    }

    int peek()
    {
        if (head == nullptr)
        { // Check if stack is empty
            cout << "Stack is empty." << endl;
            return -1; // Or throw an exception
        }
        return head->data; // Return the data of the top element
    }

    bool isEmpty()
    {
        return (head == nullptr); // Return true if stack is empty
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Destructor to free allocated memory
    ~Stack()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }
};

int main()
{

    Stack stack2;
    stack2.push(5);
    stack2.push(15);
    stack2.push(25);
    stack2.display(); // Output: Stack elements: 25 15 5

    cout << "Top element is: " << stack2.peek() << endl; // Output: Top element is: 25
    cout << "Popped: " << stack2.pop() << endl;          // Output: Popped: 25
    stack2.display();                                    // Output: Stack elements: 15 5

    while (!stack2.isEmpty())
    {
        cout << "Popped: " << stack2.pop() << endl;
    }
    stack2.pop();     // Attempt to pop from an empty stack (Stack Underflow!)
    stack2.display(); // Output: Stack is empty.
    return 0;
}