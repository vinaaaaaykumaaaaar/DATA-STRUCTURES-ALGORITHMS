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

int solve(Node *head)
{

    map<Node, int> m;
    int t = 1;
    Node *temp = head;
    int value;

    while (temp != nullptr)
    {
        // if (m.find(temp))
        // {
        //     value = m[temp];
        //     return t - value;
        // }

        // m[temp] = t;
        // ++t;
        // temp = temp->next;
    }

    return -1;
}

bool loop(Node *head)
{
    Node *fast = head, *slow = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

int res(Node *head)
{
    if (loop(head))
    {
        Node *fast = head;
        fast = fast->next->next;
        int c = 2;

        while (fast != head)
        {
            fast = fast->next->next;
            c += 2;
        }
        return c;
    }
}

int main()
{

    vector<int> a = {};
    int n, m, i, k;
    return 0;
}