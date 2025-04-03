#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1 = 0, Node *next1 = nullptr)
    {
        data = data1;
        next = next1;
    }
};

int main()
{

    Node n = Node(20);

    cout << n.data << "->" << n.next;
}