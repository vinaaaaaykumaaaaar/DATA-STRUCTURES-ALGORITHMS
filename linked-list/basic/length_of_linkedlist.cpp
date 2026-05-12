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


class LinkedList_Operation
{
    public : 
        // Function to insert at the head position
        Node* insert_at_head(Node* head , int data1)
        {
            Node* new_node = new Node(data1 , head);
            return new_node;
        }

        // Function to delete at the head position
        Node* delete_at_head(Node* head)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        // Function to find the length of the linked list
        int length(Node* head)
        {
            Node* temp = head; 
            int count = 0;

            while(temp != nullptr)
            {
                count++; 
                temp= temp->next;
            }

            return count;
        }

        // Print all the nodes
        void print_list(Node* head) {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main()
{
  
    Node* head = new Node(2);
    head->next = new Node(3);

    LinkedList_Operation link;

    cout<<"Original List : ";
    link.print_list(head);

    cout<<"The lenght of the linked list is : "<<link.length(head)<<endl;

    return 0;
}