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

Node *convert(vector<int> &arr)
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

    vector<int> arr = {23, 2, 3, 24, 6, 62, 22, 232};

    Node *head = convert(arr);

    int count = 0;
    while (head->next)
    {

        count++, head = head->next;
    }
    cout << count << endl;
}