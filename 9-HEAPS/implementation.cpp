#include <iostream>
#include <vector>

using namespace std;

class Heap
{

private:
    vector<int> array;
    int size;

    void heapify(int i);

public:
    Heap(int capacity);
    void insert(int key);
    int extractMax();
    int getMax() const;
    void deleteKey(int i);
    void increaseKey(int i, int newValue);
    void printHeap() const;
};