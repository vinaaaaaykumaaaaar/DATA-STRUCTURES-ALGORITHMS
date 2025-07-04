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
};

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

int main()
{

    Node *root = new Node(10);

    // manual building;
    root->leftChild = new Node(20);
    root->rightChild = new Node(30);

    root->leftChild->leftChild = new Node(40);
    root->leftChild->rightChild = new Node(50);

    root->rightChild->rightChild = new Node(60);

    std::cout << "--------------- Preorder Traversal ---------------" << std::endl;
    preorder(root);
    std::cout << std::endl;

    std::cout << "--------------- Inorder Traversal ---------------" << std::endl;
    inorder(root);
    std::cout << std::endl;

    std::cout << "--------------- Postorder Traversal ---------------" << std::endl;
    postorder(root);
    std::cout << std::endl;
}