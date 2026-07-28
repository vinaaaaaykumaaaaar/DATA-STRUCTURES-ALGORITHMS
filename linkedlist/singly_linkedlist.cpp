#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~LinkedList() { clear(); }

    void clear()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    // TC -> O(1)
    int get_size()
    {
        return size;
    }

    // Display -> TC -> O(n);
    void display()
    {
        Node *temp = head;
        if (!head)
        {
            cout << "Linked list is empty" << "\n";
            return;
        }
        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // TC -> O(n)
    Node *get_head()
    {
        return head;
    }

    void insert_at_head(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        if (!tail)
            tail = head;
        size++;
    }

    void insert_at_end(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LinkedList ll;
    cout << ll.get_size() << "\n";
    ll.display();
    ll.insert_at_head(10);
    ll.display();
    ll.insert_at_head(20);
    ll.display();
    ll.insert_at_end(5);
    ll.display();

    return 0;
}