#include <iostream>
using namespace std;

class Hero
{
    int i;
    char j;

public:
    long long n;

public:
    void adsf(int data, char data1, long long data2)
    {
        this->i = data;
        this->j = data1;
        this->n = data2;
    }

    void printF()
    {
        cout << "i : " << this->i << endl;
        cout << "j : " << this->j << endl;
        cout << "n : " << this->n << endl;
    }
};

int main()
{

    Hero h;
    h.adsf(10, 'A', 100000);
    h.printF();

    cout << sizeof(h) << endl;

    Hero *h1 = new Hero;
    cout << (*h1).n << endl;

    return 0;
}