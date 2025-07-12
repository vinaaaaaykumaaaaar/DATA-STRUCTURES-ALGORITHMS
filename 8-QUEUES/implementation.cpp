#include <iostream>
#include <queue>
#define max 1000
using namespace std;

class Queue
{
private:
    int arr[max];
    int rear;
    int front;

public:
    Queue()
    {
        rear = -1;
        front = -1;
    }
    void push()
    {
        if (rear >= max)
        {
            cout << "Queue is full" << endl;
            return;
        }
    }
};

int main()
{
    queue<int> q;
}