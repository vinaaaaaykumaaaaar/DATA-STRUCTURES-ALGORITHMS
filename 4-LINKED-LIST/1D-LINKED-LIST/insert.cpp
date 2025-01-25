#include <iostream>
#include <vector>

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

    vector<int> arr = {12, 8, 5, 7};
    int val = 100;

    // Creating a linked list with initial elements from the array
    Node *head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);

    Node *temp = new Node(val, head);

    head = temp;

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}