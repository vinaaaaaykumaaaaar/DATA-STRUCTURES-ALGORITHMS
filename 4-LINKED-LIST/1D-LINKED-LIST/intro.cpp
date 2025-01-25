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

    vector<int> a = {1, 2, 3, 4, 5};
    Node *y = new Node(a[4]);
    Node *z = new Node(a[1], y);
    cout << z->data << " " << z->next->data;

    return 0;
}