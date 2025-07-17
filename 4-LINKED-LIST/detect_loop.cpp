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

bool solve(Node *head)
{

    map<Node *, int> m;

    Node *temp = head;

    while (temp != nullptr)
    {
        // if (m.find(temp))
        // {

        //     return true;
        // }

        m[temp] = 1;
        temp = temp->next;
    }
}

bool optimized(Node *head)
{

    Node *fast = head, *slow = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        if (fast == slow)
        {
            return true;
        }
        fast = fast->next->next;
        slow = slow->next;
    }

    return false;
}

int main()
{

    vector<int> a = {};
    int n, m, i, k;
    return 0;
}