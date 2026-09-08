/*

The fundamental operations are:

push() → add an element
pop() → remove the top element
top() / peek() → inspect the top element
empty() → check whether stack is empty
size() → number of elements

*/

#include <iostream>
using namespace std;

// ARRAY based STACK

class Stack
{
private:
    int *arr;
    int capacity;
    int topIndex;

public:
    Stack(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        topIndex = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int element)
    {
        if (topIndex == capacity - 1)
        {
            throw overflow_error("Stack Overflow");
        }

        topIndex++;
        arr[topIndex] = element;
    }

    void pop()
    {
        if (topIndex == -1)
        {
            throw underflow_error("Stack Underflow");
        }

        topIndex--;
    }

    int top()
    {
        if (topIndex == -1)
        {
            throw underflow_error("Stack is empty");
        }

        return arr[topIndex];
    }

    bool empty()
    {
        return topIndex == -1;
    }

    int size()
    {
        return topIndex + 1;
    }
};

int main()
{

    Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl; // 30

    st.pop();

    cout << st.top() << endl; // 20

    cout << st.size() << endl; // 2

    cout << st.empty() << endl; // 0 (false)

    return 0;
}