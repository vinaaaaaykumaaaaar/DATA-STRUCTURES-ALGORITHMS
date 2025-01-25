#include <iostream>

using namespace std;

class Node
{

public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

int main()
{

    Node *head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);

    Node *temp = head;
    int cnt = 0;
    // Traverse the linked list and count nodes
    while (temp != NULL)
    {
        temp = temp->next;
        cnt++; // increment cnt for every node traversed
    }

    cout << cnt;
}