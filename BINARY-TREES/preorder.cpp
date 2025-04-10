#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data1)
    {
        this->data = data1;
        this->next = this->prev = nullptr;
    }
};

void pre_order(Node *node)
{
    if (node == nullptr)
        return;

    cout << node->data << endl;
    pre_order(node->prev);
    pre_order(node->next);
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
}