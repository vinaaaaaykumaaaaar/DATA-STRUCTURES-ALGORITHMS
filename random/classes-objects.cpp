#include <iostream>

using namespace std;

class Counter
{
public:
    int count;

    void increment()
    {
        count++;
    }

    int get()
    {
        return count;
    }
};

int main()
{

    Counter c;
    c.count = 0;
    c.increment();
    cout << c.get() << endl;

    return 0;
}