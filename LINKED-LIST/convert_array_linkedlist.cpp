#include <iostream>
#include <vector>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int data1)
    {
        this->data = data1;
        this->next = nullptr;
    }

    Node(int data1, Node *next1)
    {
        this->data = data1;
        this->next = next1;
    }

    Node()
    {
        this->data = -100;
        this->next = nullptr;
    }
};

Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;

    for (int i = 0; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    Node *head = convertArr2LL(arr);
    while (head)
    {
        cout << head->data << "->" << head->next << endl;
        head = head->next;
    }
}