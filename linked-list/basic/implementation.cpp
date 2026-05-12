#include<iostream>
using namespace std; 

class Node
{
    public : 
        int data; 
        Node* next;

        // construtor with no data 
        Node()
        {
            this->data = 0;
            this->next = nullptr;
        }

        // construtor with data
        Node(int data1)
        {
            this->data = data1;
            this->next = nullptr;
        }

        // construtor with data and next pointer
        Node (int data1 , Node* next1)
        {
            this->data = data1;
            this->next = next1;
        }
};

int main()
{
  
    Node* C = new Node(3);
    Node* B = new Node(2,C);
    Node* A = new Node(1,B);



    cout<<A->data<<" "<<A->next<<endl;
    cout<<B->data<<" "<<B->next<<endl;
    cout<<C->data<<" "<<C->next<<endl;

    return 0;
}