/*
What vector really is ?

Dynamic array. Contiguous memory like array, but grows automatically. size() = how many elements you have, capacity() = how much memory is allocated. When size == capacity and you push_back, it doubles capacity internally.

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // declaration methods
    vector<int> a;             // empty
    vector<int> b(5);          // [0,0,0,0,0] size 5
    vector<int> c(5, -1);      // [-1,-1,-1,-1,-1]
    vector<int> d = {1, 2, 3}; // initialization
    vector<int> e(d);          // copy of d

    // 2D vector
    vector<vector<int>> mat(10, vector<int>(10, 0)); // 10*10 matrix

    return 0;
}

