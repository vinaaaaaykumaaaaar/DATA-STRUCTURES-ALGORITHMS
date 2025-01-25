#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
};

int main()
{
    Node *head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);

    Node *temp = head;

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    while (head != NULL)
    {
        if (head->next->next == NULL)
        {
            head->next = nullptr;
        }

        head = head->next;
    }

     while (temp->next->next != NULL) {
        temp = temp->next;
    }
    // Delete the last node
    delete temp->next;
    // Set the next of the second last node to nullptr, effectively removing the last node
    temp->next = nullptr;
}