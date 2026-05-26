/*
Search an element in a Linked List

Problem Statement: Given the head of a linked list and an integer value, find out whether the integer is present in the linked list or not. Return true if it is present, or else return false.

Input: 0->1->2, val = 2
Output: True
Explanation: Since element 2 is present in the list, return true.

Input: 12->5->8->7, val = 6
Output: False
Explanation: The list does not contain element 6. Therefore, return false.
*/

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor with no data
    Node()
    {
        this->data = 0;
        this->next = nullptr;
    }

    // constructor with data
    Node(int data1)
    {
        this->data = data1;
        this->next = nullptr;
    }

    // constructor with data and next pointer
    Node(int data1, Node *next1)
    {
        this->data = data1;
        this->next = next1;
    }
};

class Linkedlist
{
public:
    bool search_in_linkedlist(Node *head, int target)
    {
        Node *temp = head;

        if (temp == nullptr)
            return false;

        while (temp != nullptr)
        {
            if (temp->data == target)
            {
                return true;
            }

            temp = temp->next;
        }

        return false;
    }

    // Print all the nodes
    void print_list(Node *head)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{

    Node *head = new Node(12);
    head->next = new Node(5);
    head->next->next = new Node(8);
    head->next->next->next = new Node(7);

    Linkedlist link;

    cout << "Original List : ";
    link.print_list(head);

    if (link.search_in_linkedlist(head, 8))
    {
        cout << "found" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}
