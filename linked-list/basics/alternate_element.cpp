/*
Given the head of a linked list , delete every alternate element from the list starting from the second element

input :
    n = 6
    list = 1 -> 2 -> 3 -> 4 -> 5 -> 6
output :
    1 -> 3 -> 5
*/

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

void print(Node *head)
{
    Node *temp = head;

    if (temp == nullptr)
    {
        cout << "linked list is empty " << endl;
        return;
    }

    while (temp)
    {
        cout << temp->data << " ->  ";
        temp = temp->next;
    }
    cout << "null" << endl;
}

void insertAtHead(Node *&head, int value)
{
    Node *newNode = new Node(value);

    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node *&head, int value)
{
    if (head == nullptr)
    {
        insertAtHead(head, value);
        return;
    }

    Node *newNode = new Node(value);

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void deleteAlternateNode(Node *&head)
{
    Node *temp = head;

    while (temp != nullptr && temp->next != nullptr)
    {
        Node *deleteNode = temp->next;
        temp->next = temp->next->next;
        temp = temp->next;

        delete deleteNode;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *node = new Node(10);
    insertAtEnd(node, 20);
    insertAtEnd(node, 30);
    insertAtEnd(node, 40);
    insertAtEnd(node, 50);

    print(node);

    deleteAlternateNode(node);

    print(node);

    return 0;
}