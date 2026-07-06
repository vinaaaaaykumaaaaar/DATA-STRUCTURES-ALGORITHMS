#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node() : data(0), next(nullptr) {};
    Node(int value) : data(value), next(nullptr) {};
    Node(int value, Node *next_node) : data(value), next(next_node) {};
};

class LinkedList
{
public:
    bool is_empty(Node *head)
    {
        return head = nullptr;
    }

    Node *insert_at_tail(Node *head, int data)
    {
        Node *new_node = new Node(data);
        if (head == nullptr)
        {
            return new_node;
        }
    }
};

int main()
{

    LinkedList list;
    Node *head = nullptr;

    cout << head->data << endl;

    head = list.insert_at_tail(head, 10);
    cout << head->data << endl;

    return 0;
}