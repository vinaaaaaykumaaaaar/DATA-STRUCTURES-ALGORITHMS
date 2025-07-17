

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <list>

struct Node
{
    int data;
    Node *next;
};

using namespace std;

void solve(Node *head)
{

    Node *fast = head, *slow = head;

    while (fast != nullptr && fast->next != nullptr)
    {

        fast = fast->next->next;
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