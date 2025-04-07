#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data1, Node *next1, Node *prev1)
    {
        this->data = data1;
        this->next = next1;
        this->prev = prev1;
    }

    Node(int data1, Node *next1)
    {
        this->data = data1;
        this->next = next1;
        this->prev = nullptr;
    }

    Node(int data1)
    {
        this->data = data1;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    Node *head = new Node(v[0]);
    Node *mover = head;

    for (int i = 1; i < v.size(); i++)
    {
        Node *temp = new Node(v[i]);
        temp->prev = mover;
        mover->next = temp;
        mover = temp;
    }

    cout << "--------------------------\n";

    Node *temp = head;

    while (temp)
    {
        cout << temp->prev << " --> " << temp->data << " --> " << temp->next << endl;
        temp = temp->next;
    }
}