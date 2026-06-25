#include <iostream>
using namespace std;

class Node
{
public:
    int data = 10;
    Node *p;

    Node()
    {
    }
};

int main()
{
    int x = 42;
    int *p;
    cout << *p << endl;

    Node *temp = new Node();

    cout << temp->data << endl;

    return 0;
}
