#include <iostream>

using namespace std;

class Stack
{
private:
    struct Node
    {
        int value;
        Node *next;

        Node(int value, Node *next = nullptr)
        {
            this->value = value;
            this->next = next;
        }
    };

    Node *topNode;
    int stackSize;

public:
    Stack()
    {
        topNode = nullptr;
        stackSize = 0;
    }

    ~Stack()
    {
        while (!empty())
        {
            pop();
        }
    }

    void push(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;

        stackSize++;
    }

    void pop()
    {
        if (empty())
        {
            throw underflow_error("Stack is empty");
        }

        Node *temp = topNode;
        topNode = topNode->next;

        delete temp;
        stackSize--;
    }

    int top() const
    {
        if (empty())
        {
            throw underflow_error("Stack is empty");
        }

        return topNode->value;
    }

    bool empty() const
    {
        return topNode == nullptr;
    }

    int size() const
    {
        return stackSize;
    }
};

int main()
{

    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl; // 30

    st.pop();

    cout << st.top() << endl; // 20

    return 0;
}