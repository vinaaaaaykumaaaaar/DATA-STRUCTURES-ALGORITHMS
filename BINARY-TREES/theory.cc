/**
--------------------------------------  BINARY TREES IN C++ -----------------------------------------

  INTRODUCTION:

   A binary tree is a hierarchical data structure where each node has at most two children,
   referred to as the left child and the right child. The topmost node is called the root

   Key Terminology:
     - Root: The topmost node of the tree.
     - Node: Each element in the tree containing data and pointers to children.
     - Leaf: A node with no children.
     - Internal Node: A node with at least one child.
     - Edge: The connection between two nodes.
     - Depth: The length of the path from the root to a node.
     - Height: The length of the longest path from a node to a leaf.
     - Subtree: A tree consisting of a node and all its descendants.

   Types of Binary Trees:
     1. Full Binary Tree: Every node has 0 or 2 children.
     2. Complete Binary Tree: All levels are filled except possibly the last level, which is filled from left to right.
     3. Perfect Binary Tree: All internal nodes have two children and all leaves are at the same level.
     4. Balanced Binary Tree: The height of the left and right subtrees of any node differ by no more than 1.
     5. Binary Search Tree (BST): For each node, all elements in the left subtree are less than the node,
        and all elements in the right subtree are greater than the node.

   Time Complexity (for a balanced tree):
    - Access: O(log n)
    - Search: O(log n)
    - Insertion: O(log n)
    - Deletion: O(log n)

   Space Complexity: O(n) for storage of n nodes.

   Applications:
    - Expression trees in compilers
    - Huffman coding trees for data compression
    - Binary Search Trees for efficient searching
    - Priority Queues
    - Syntax trees in parsing

  */


#include<iostream>
#include<queue>

using namespace std;

template <typename T>
class TreeNode
{
    public:
        T data;
        TreeNode* left;
        TreeNode* right;

        // constructor
        TreeNode(T value) : data(value) , left(nullptr) , right(nullptr) {}

};

// Binary Tree Class
template <typename T>
class BinaryTree 
{
    private:
        TreeNode<T>* root;

        // Private helper functions for recursive operations


}
















