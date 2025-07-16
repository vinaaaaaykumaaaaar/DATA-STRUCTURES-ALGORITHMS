#include <iostream>

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *prev;
        Node *next;

        Node(int data, Node *nextPtr = nullptr, Node *prevPtr = nullptr)
        {
            this->data = data;
            this->prev = prevPtr;
            this->next = nextPtr;
        }
    };

    Node *head;
    size_t count;

public:
    LinkedList()
    {
        head = nullptr;
        count = 0;
    }

    void insertAtFront(int value)
    {
        head = new Node(value, head, nullptr);
        ++count;
    }

    void insertAtEnd(int value)
    {
        if (head == nullptr)
        {
            insertAtFront(value);
            return;
        }

        Node *curr = head;

        while (curr->next != nullptr)
        {
            curr = curr->next;
        }

        curr->next = new Node(value, nullptr, curr);
        ++count;
    }

    void display()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }

    void size()
    {
        std::cout << count << std::endl;
    }
};

int main()
{
    LinkedList list;
    list.insertAtFront(10);
    list.insertAtEnd(20);
    list.insertAtEnd(20);
    list.display();
    list.size();

    return 0;
}