#include <iostream>
#include <vector>

using namespace std;

// 0 -> 1 -> 2002 , 2001 -> 2 -> 2003 , 2002 -> 3 -> 2004, 2003 -> 4 -> 0

class Node
{

public:
    int data;
    Node *next;
    Node *prev;

    Node(int data1)
    {
        this->data = data1;
        this->next = nullptr;
        this->prev = nullptr;
    }

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
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    Node *head = new Node(v[0]);
    Node *mover = head;

    for (int i = 1; i < v.size(); i++)
    {
        Node *temp = new Node(v[i]);
        mover->next = temp;
        temp->prev = mover;
        mover = temp;
    }

    Node *temp = head;

    while (temp)
    {

        cout << temp->prev << " -> " << temp->data << " -> " << temp->next << endl;

        temp = temp->next;
    }

    temp = head;

    cout << "---------------------------------------" << endl;

    while (temp)
    {

        if (temp->next == nullptr)
        {
            head = temp;
        }
        swap(temp->next, temp->prev);
        temp = temp->prev;
    }

    cout << head->data;

    temp = head;

    cout << "---------------------------------------" << endl;

    while (temp)
    {

        cout << temp->prev << " -> " << temp->data << " -> " << temp->next << endl;

        temp = temp->next;
    }
}