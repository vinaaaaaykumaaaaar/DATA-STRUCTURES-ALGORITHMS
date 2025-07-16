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

    bool remove(int value)
    {
        if (head == nullptr)
        {
            std::cout << "linked list is empty" << std::endl;
            return false;
        }

        Node *curr = head;

        while (curr != nullptr)
        {
            if (curr->data == value)
            {
                if (curr->prev != nullptr)
                {
                    Node *prev = curr->prev, *next = curr->next;
                    prev->next = next;
                    next->prev = prev;
                }
                else
                {
                    head = curr->next;
                }

                delete curr;
                --count;

                return true;
            }

            curr = curr->next;
        }

        return false;
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
    list.insertAtFront(20);
    list.insertAtEnd(30);
    list.insertAtFront(10);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.display();
    list.size();

    list.remove(10);
    list.display();
    list.size();

    list.remove(40);
    list.display();
    list.size();

    return 0;
}