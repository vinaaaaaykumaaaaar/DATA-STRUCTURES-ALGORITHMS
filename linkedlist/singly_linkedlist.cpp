#include <bits/stdc++.h>
using namespace std;

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

public:
    LinkedList() : head(nullptr), tail(nullptr), sz(0) {}

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
        sz = 0;
    }

    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        if (!tail)
            tail = head;
        sz++;
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

    int findLenght()
    {
        if (!head)
            return 0;
        Node *curr = head;
        int count = 0;
        while (curr)
        {
            count++;
            curr = curr->next;
        }

        return count;
    }

    int size()
    {
        return sz;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LinkedList ll;
    ll.insertAtBeginning(10);
    ll.insertAtBeginning(20);
    ll.insertAtBeginning(30);

    cout << ll.size() << "\n";
    ll.deleteAtBeginning();
    cout << ll.size() << "\n";

    cout << ll.findLenght() << "\n";
}
