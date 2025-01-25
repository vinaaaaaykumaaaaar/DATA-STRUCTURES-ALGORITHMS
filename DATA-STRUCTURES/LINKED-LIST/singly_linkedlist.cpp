#include <iostream>

using namespace std;

// singly linked list Node
class Node
{
public:
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {};
};

class Linkedlist
{
public:
    Node *head;

    Linkedlist() : head(nullptr) {};

    // inserting at the beginning of the linkedlist
    void insertAtBeginning(int data)
    {
        auto newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int data)
    {
        auto newNode = new Node(data);

        if (!head)
        {
            insertAtBeginning(data);
            return;
        }

        auto temp = head;

        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void display()
    {
        auto temp = head;

        if (!temp)
        {
            cout << "Linked list is empty" << endl;
            return;
        }

        while (temp)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main()
{

    Linkedlist l;
    l.insertAtBeginning(10);
    l.insertAtBeginning(20);
    l.insertAtBeginning(30);
    l.insertAtEnd(40);
    l.insertAtEnd(50
    l.display();
}