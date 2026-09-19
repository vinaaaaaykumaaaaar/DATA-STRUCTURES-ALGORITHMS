#include <iostream>
using namespace std;

class LinkedList
{
private:
};

int main()
{
    int *a = new int[10];
    a[0] = 10;
    a[2] = 20;

    cout << a[0] << " " << a[1] << endl;
}