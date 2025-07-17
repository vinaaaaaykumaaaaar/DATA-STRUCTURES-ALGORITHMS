#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <list>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *loop(Node *head)
{
    Node *fast = head, *slow = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            return fast;
        }
    }

    return nullptr;
}

Node *start(Node *head)
{

    Node *fast = loop(head);

    if (fast != nullptr)
    {
        Node *slow = head;
        while (fast != slow)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
    else
        return nullptr;
}
int main()
{
    return 0;
}
