#include <iostream>
#include <stdexcept>
using namespace std;

class Stack
{
private:
    int *arr;
    int capacity;
    int topIndex;

    void resize()
    {
        int newCapacity = capacity * 2;

        int *newArr = new int[newCapacity];

        for (int i = 0; i <= topIndex; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;

        arr = newArr;

        capacity = newCapacity;
    }

public:
    Stack(int initialCapacity = 2)
    {
        capacity = initialCapacity;
        arr = new int[capacity];
        topIndex = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int value)
    {
        if (topIndex == capacity - 1)
        {
            resize();
        }
        topIndex++;
        arr[topIndex] = value;
    }

    void pop()
    {
        if (empty())
        {
            throw underflow_error("Stack underflow");
        }
        topIndex--;
    }

    bool empty() const
    {
        return topIndex == -1;
    }

    int top() const
    {
        if (empty())
        {
            throw underflow_error("Stack is empty");
        }

        return arr[topIndex];
    }

    int size() const
    {
        return topIndex + 1;
    }
};

int main()
{
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout << "Top: " << st.top() << endl;
    cout << "Size: " << st.size() << endl;

    st.pop();

    cout << "Top: " << st.top() << endl;

    return 0;
}