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

void insertAtPosition(Node *&head, int value, int k)
{
    if (k < 1)
        return;

    if (k == 1)
    {
        insertAtHead(head, value);
        return;
    }

    Node *pos = head;

    int c = 1;

    for (int i = 1; i < k - 1 && pos != nullptr; i++)
    {
        pos = pos->next;
    }

    if (pos == nullptr)
        return;

    // Create new node
    Node *newNode = new Node(value);

    // Connect the new node
    newNode->next = pos->next;
    pos->next = newNode;
}

void deleteAtFront(Node *&head)
{
    if (head == nullptr)
        return;

    Node *nodeToDelete = head;

    head = head->next;

    delete nodeToDelete;
}

void deleteAtEnd(Node *&head)
{
    // Case 1: Empty list
    if (head == nullptr)
        return;

    // Case 2: Only one node
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    // Case 3: Multiple nodes
    Node *temp = head;

    // Stop at the second-last node
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    // Delete the last node
    Node *nodeToDelete = temp->next;

    temp->next = nullptr;

    delete nodeToDelete;
}

void deleteAtPos(Node *&head, int k)
{
    // Invalid position or empty list
    if (head == nullptr || k < 1)
        return;

    // Case 1: Delete the first node
    if (k == 1)
    {
        Node *temp = head;

        head = head->next;

        delete temp;
        return;
    }

    // Case 2: Find the node before the target
    Node *prev = head;

    for (int i = 1; i < k - 1 && prev != nullptr; i++)
    {
        prev = prev->next;
    }

    // Check whether target node exists
    if (prev == nullptr || prev->next == nullptr)
        return;

    // Delete the target node
    Node *nodeToDelete = prev->next;

    prev->next = nodeToDelete->next;

    delete nodeToDelete;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(30);
    Node *node4 = new Node(40);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    print(node1);
    insertAtHead(node1, 5);
    print(node1);
    insertAtEnd(node1, 50);
    print(node1);
    insertAtPosition(node1, 25, 4);
    print(node1);
    deleteAtFront(node1);

    print(node1);
    deleteAtEnd(node1);
    print(node1);

    deleteAtPos(node1, 3);
    print(node1);

    return 0;
}