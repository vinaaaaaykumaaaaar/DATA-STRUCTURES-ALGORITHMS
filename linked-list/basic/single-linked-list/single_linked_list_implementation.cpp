/*
Singly Linked List — full implementation with its core properties.

A singly linked list is a chain of nodes where each node stores a value and a
pointer to the next node. The list is identified by its `head` pointer; an
empty list has `head == nullptr`.

Operations implemented below:
  - insert_at_head / insert_at_tail / insert_at_position
  - delete_at_head / delete_at_tail / delete_at_position / delete_value
  - search                       (does the list contain a value?)
  - length                       (number of nodes)
  - is_empty                     (head == nullptr)
  - get_at                       (value at index)
  - reverse                      (in-place reversal)
  - print_list                   (forward traversal)
  - clear                        (delete every node, free memory)

Time/space complexity is noted on each function.
*/

#include <iostream>
using namespace std;

// ---------- Node -------------------------------------------------------------

class Node
{
public:
    int data;
    Node *next;

    Node() : data(0), next(nullptr) {}

    Node(int value) : data(value), next(nullptr) {}

    Node(int value, Node *next_node) : data(value), next(next_node) {}
};

// ---------- LinkedList operations -------------------------------------------

class LinkedList
{
public:
    // O(1) — true when the list has no nodes.
    bool is_empty(Node *head)
    {
        return head == nullptr;
    }

    // O(n) — walks every node once.
    int length(Node *head)
    {
        int count = 0;
        for (Node *curr = head; curr != nullptr; curr = curr->next)
        {
            count++;
        }
        return count;
    }

    // O(n) — linear scan from the head.
    bool search(Node *head, int target)
    {
        for (Node *curr = head; curr != nullptr; curr = curr->next)
        {
            if (curr->data == target)
                return true;
        }
        return false;
    }

    // O(n) — returns the value at `index`, or throws if out of range.
    int get_at(Node *head, int index)
    {
        if (index < 0)
            throw out_of_range("index must be >= 0");

        Node *curr = head;
        for (int i = 0; i < index && curr != nullptr; i++)
        {
            curr = curr->next;
        }
        if (curr == nullptr)
            throw out_of_range("index out of range");
        return curr->data;
    }

    // O(1) — new node becomes the head.
    Node *insert_at_head(Node *head, int value)
    {
        return new Node(value, head);
    }

    // O(n) — walks to the last node, then links a new one.
    Node *insert_at_tail(Node *head, int value)
    {
        Node *new_node = new Node(value);
        if (head == nullptr)
            return new_node;

        Node *curr = head;
        while (curr->next != nullptr)
            curr = curr->next;
        curr->next = new_node;
        return head;
    }

    // O(n) — inserts before `index`. Index 0 inserts at head.
    Node *insert_at_position(Node *head, int index, int value)
    {
        if (index < 0)
            throw out_of_range("index must be >= 0");
        if (index == 0)
            return insert_at_head(head, value);

        Node *prev = head;
        for (int i = 0; i < index - 1 && prev != nullptr; i++)
        {
            prev = prev->next;
        }
        if (prev == nullptr)
            throw out_of_range("index out of range");

        prev->next = new Node(value, prev->next);
        return head;
    }

    // O(1) — drops the head and frees it. No-op on an empty list.
    Node *delete_at_head(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        Node *next = head->next;
        delete head;
        return next;
    }

    // O(n) — walks to the second-to-last node and frees the tail.
    Node *delete_at_tail(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
        {
            delete head;
            return nullptr;
        }

        Node *prev = head;
        while (prev->next->next != nullptr)
            prev = prev->next;
        delete prev->next;
        prev->next = nullptr;
        return head;
    }

    // O(n) — deletes the node at `index`.
    Node *delete_at_position(Node *head, int index)
    {
        if (head == nullptr)
            throw out_of_range("cannot delete from empty list");
        if (index < 0)
            throw out_of_range("index must be >= 0");
        if (index == 0)
            return delete_at_head(head);

        Node *prev = head;
        for (int i = 0; i < index - 1 && prev->next != nullptr; i++)
        {
            prev = prev->next;
        }
        if (prev->next == nullptr)
            throw out_of_range("index out of range");

        Node *victim = prev->next;
        prev->next = victim->next;
        delete victim;
        return head;
    }

    // O(n) — deletes the first node whose data equals `value`. Returns the
    // (possibly new) head; the list is unchanged if the value is absent.
    Node *delete_value(Node *head, int value)
    {
        if (head == nullptr)
            return nullptr;
        if (head->data == value)
            return delete_at_head(head);

        Node *prev = head;
        while (prev->next != nullptr && prev->next->data != value)
        {
            prev = prev->next;
        }
        if (prev->next != nullptr)
        {
            Node *victim = prev->next;
            prev->next = victim->next;
            delete victim;
        }
        return head;
    }

    // O(n), O(1) extra space — reverses links in place and returns new head.
    Node *reverse(Node *head)
    {
        Node *prev = nullptr;
        Node *curr = head;
        while (curr != nullptr)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // O(n) — prints "a -> b -> c -> nullptr".
    void print_list(Node *head)
    {
        for (Node *curr = head; curr != nullptr; curr = curr->next)
        {
            cout << curr->data << " -> ";
        }
        cout << "nullptr" << endl;
    }

    // O(n) — frees every node and returns nullptr.
    Node *clear(Node *head)
    {
        while (head != nullptr)
        {
            Node *next = head->next;
            delete head;
            head = next;
        }
        return nullptr;
    }
};

// ---------- Demo -------------------------------------------------------------

int main()
{
    LinkedList list;
    Node *head = nullptr;

    // Build: 10 -> 20 -> 30
    head = list.insert_at_tail(head, 10);
    head = list.insert_at_tail(head, 20);
    head = list.insert_at_tail(head, 30);
    cout << "Initial list      : ";
    list.print_list(head);

    // Insert at head: 5 -> 10 -> 20 -> 30
    head = list.insert_at_head(head, 5);
    cout << "After insert head : ";
    list.print_list(head);

    // Insert 15 at index 2: 5 -> 10 -> 15 -> 20 -> 30
    head = list.insert_at_position(head, 2, 15);
    cout << "After insert @ 2  : ";
    list.print_list(head);

    // Properties
    cout << "Length            : " << list.length(head) << endl;
    cout << "Is empty          : " << boolalpha << list.is_empty(head) << endl;
    cout << "Search 20         : " << boolalpha << list.search(head, 20) << endl;
    cout << "Search 99         : " << boolalpha << list.search(head, 99) << endl;
    cout << "Value at index 3  : " << list.get_at(head, 3) << endl;

    // Delete operations
    head = list.delete_at_head(head);
    cout << "After delete head : ";
    list.print_list(head);

    head = list.delete_at_tail(head);
    cout << "After delete tail : ";
    list.print_list(head);

    head = list.delete_value(head, 15);
    cout << "After delete 15   : ";
    list.print_list(head);

    // Reverse
    head = list.reverse(head);
    cout << "After reverse     : ";
    list.print_list(head);

    // Cleanup
    head = list.clear(head);
    cout << "After clear       : ";
    list.print_list(head);

    return 0;
}
