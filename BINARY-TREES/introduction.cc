/*
----------------------------------------------  B I N A R Y  - T R E E S -----------------------------------------------------

Rules :
    - at most 2 children
    - exactly 1 root 
    - exactly 1 path b/w root and any node

*/


#include<iostream>

using namespace std;

class Node
{
    public:
        char data;
        Node* left;
        Node* right;

        Node(char data1)
        {
            data = data1;
            left = nullptr;
            right = nullptr;

        }

};

int main()
{
    Node* a = new Node('a');
    Node* b = new Node('b');
    Node* c = new Node('c');
    Node* d = new Node('d');
    Node* e = new Node('e');
    Node* f = new Node('f');

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;

    return 0;

}
