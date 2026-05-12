#include<iostream>

class LinkedList
{
    public : 
        int data; 
        Node* next; 

        // Constructor with data and next
        Node(int data1, Node* next1)
        {
            data = data1;
            next = next1;
        }

        // Constructor with only data
        Node(int data1) 
        {
            data = data1;
            next = nullptr;
        }
};