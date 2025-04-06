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
        this->data = data1;
        this->next = next1;
    }

    Node(int data1)
    {
        this->data = data1;
        this->next = nullptr;
    }
    Node()
    {
        this->data = 0;
        this->next = nullptr;
    }
};

int main()
{

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    Node *head = new Node(v[0]);
    Node *prev = head;

    for (int i = 1; i < v.size(); i++)
    {

        Node *temp = new Node(v[i]);
        prev->next = temp;

        prev = temp;
    }

    Node *temp = head;

    while (temp)
    {
        cout << temp->data << " ->  " << temp->next << endl;
        temp = temp->next;
    }

    temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;

    temp->next = nullptr;

    temp = head;

    cout << "-----------------------\n";

    while (temp)
    {
        cout << temp->data << " ->  " << temp->next << endl;
        temp = temp->next;
    }
}