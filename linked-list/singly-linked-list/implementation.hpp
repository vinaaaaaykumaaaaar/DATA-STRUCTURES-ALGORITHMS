#pragma once

#include <iostream>
#include <utility>

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int sz;

    // Deep-copies every node from `other` onto the end of *this.
    // Shared by the copy constructor and copy-assignment operator.
    void copyFrom(const LinkedList &other)
    {
        Node *src = other.head;
        while (src)
        {
            insertAtEnd(src->data);
            src = src->next;
        }
    }

    void swapWith(LinkedList &other) noexcept
    {
        std::swap(head, other.head);
        std::swap(tail, other.tail);
        std::swap(sz, other.sz);
    }

public:
    LinkedList() : head(nullptr), tail(nullptr), sz(0) {}

    // ---------------- Rule of Five ----------------
    // This class owns raw heap nodes, so the compiler-generated copy
    // constructor/assignment would just copy the head/tail pointers
    // (a "shallow" copy). Two LinkedLists would then point at the same
    // nodes, and both destructors would eventually try to delete the
    // same memory -> double free / undefined behavior. Defining these
    // five explicitly is what makes `LinkedList b = a;` actually safe.

    // Copy constructor: build an independent deep copy.
    LinkedList(const LinkedList &other) : head(nullptr), tail(nullptr), sz(0)
    {
        copyFrom(other);
    }

    // Copy assignment (copy-and-swap idiom): build a deep copy of
    // `other`, then swap it into *this. Our old contents get destroyed
    // automatically when `temp` goes out of scope at the end.
    LinkedList &operator=(const LinkedList &other)
    {
        if (this != &other)
        {
            LinkedList temp(other);
            swapWith(temp);
        }
        return *this;
    }

    // Move constructor: steal the other list's pointers, leave it empty.
    LinkedList(LinkedList &&other) noexcept
        : head(other.head), tail(other.tail), sz(other.sz)
    {
        other.head = other.tail = nullptr;
        other.sz = 0;
    }

    // Move assignment: free our own nodes, then steal the other's.
    LinkedList &operator=(LinkedList &&other) noexcept
    {
        if (this != &other)
        {
            clear();
            head = other.head;
            tail = other.tail;
            sz = other.sz;
            other.head = other.tail = nullptr;
            other.sz = 0;
        }
        return *this;
    }

    ~LinkedList() { clear(); }
    // ------------------------------------------------

    void clear()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        sz = 0;
    }

    bool isEmpty() const { return sz == 0; }
    int getSize() const { return sz; }

    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        if (!tail)
            tail = head;
        sz++;
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        sz++;
    }

    void insertAtPosition(int val, int pos)
    {
        if (pos < 0 || pos > sz)
        {
            std::cout << "Invalid position\n";
            return;
        }
        if (pos == 0)
        {
            insertAtBeginning(val);
            return;
        }
        if (pos == sz)
        {
            insertAtEnd(val);
            return;
        }

        Node *temp = head;
        Node *newNode = new Node(val);
        for (int it = 0; it < pos - 1; it++)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
        sz++;
    }

    bool search(int val) const
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->data == val)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void display() const
    {
        Node *temp = head;
        while (temp)
        {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    void deleteAtBeginning()
    {
        if (!head)
            return;
        Node *temp = head;
        head = head->next;
        delete temp;
        sz--;
        if (!head)
            tail = nullptr;
    }

    void deleteAtEnd()
    {
        if (!head)
            return;
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *temp = head;
            while (temp->next != tail)
                temp = temp->next;
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        sz--;
    }

    void deleteAtPosition(int pos)
    {
        if (pos < 0 || pos >= sz || !head)
        {
            std::cout << "Invalid position\n";
            return;
        }
        if (pos == 0)
        {
            deleteAtBeginning();
            return;
        }
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
            temp = temp->next;
        Node *toDelete = temp->next;
        temp->next = toDelete->next;
        if (toDelete == tail)
            tail = temp;
        delete toDelete;
        sz--;
    }

    // NOTE: -1 doubles as both "list is empty" and a legitimate node
    // value. Fine for practice; a stricter API would use an out-param
    // or throw instead of overloading the return value.
    int middleOfLinkedList() const
    {
        if (!head)
            return -1;

        Node *slow = head;
        Node *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }
};