#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value)
    {
        this->data = value;
        this->next = nullptr;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *node1 = new Node(10);
    Node *node2 = new Node(20);

    node1->next = node2;

    cout << node1->data << endl;
    cout << node1->next->data << endl;

    return 0;
}