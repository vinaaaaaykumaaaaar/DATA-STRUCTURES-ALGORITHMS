// BINARY TREE - implementation , preorder , inorder , postorder traversal

#include <iostream>

class Node
{
public:
    int data;
    Node *leftChild;
    Node *rightChild;

    // constructor to initialize without data
    Node()
    {
        data = 0;
        leftChild = nullptr;
        rightChild = nullptr;
    }

    // constructor to initialize with data
    Node(int value)
    {
        data = value;
        leftChild = nullptr;
        rightChild = nullptr;
    }

    // preorder traversal
    void preorder(Node *root)
    {
        if (root == nullptr)
            return;

        std::cout << root->data << " ";
        preorder(root->leftChild);
        preorder(root->rightChild);
    }

    // inorder traversal
    void inorder(Node *root)
    {
        if (root == nullptr)
            return;

        inorder(root->leftChild);
        std::cout << root->data << " ";
        inorder(root->rightChild);
    }

    // postorder traversal
    void postorder(Node *root)
    {
        if (root == nullptr)
            return;

        postorder(root->leftChild);
        postorder(root->rightChild);
        std::cout << root->data << " ";
    }
};

int main()
{

    Node *n = new Node(10);
    std::cout << n->data << std::endl;
}