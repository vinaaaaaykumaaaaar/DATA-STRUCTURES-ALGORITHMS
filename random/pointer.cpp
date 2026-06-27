#include <iostream>
using namespace std;

class Node
{
public:
    int data = 10;
    Node *p;

    Node()
    {
    }
};

int main()
{
    int n = 10;

    int *p;
    p = &n;

    cout << *(&n) << endl;

    return 0;
}
