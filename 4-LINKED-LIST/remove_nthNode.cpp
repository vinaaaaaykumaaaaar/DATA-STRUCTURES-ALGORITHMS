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

void solve(Node *head, int n)
{

    Node *fast = head, *slow = head;
    int l = 0;

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

    Node *temp = slow->next;

    slow->next = slow->next->next;

    delete temp;
}

int main()
{

    return 0;
}
