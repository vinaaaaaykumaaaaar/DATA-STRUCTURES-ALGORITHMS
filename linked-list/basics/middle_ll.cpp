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

void middle(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    cout << slow->data << endl;
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
    insertAtEnd(node, 60);

    print(node);

    // deleteAlternateNode(node);

    print(node);

    middle(node);

    return 0;
}