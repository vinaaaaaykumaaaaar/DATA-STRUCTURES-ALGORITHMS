#include <iostream>

using namespace std;

class Counter
{
public:
    int count;

    Counter()
    {
        count = 10;
    }

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

    c.increment();
    c.increment();
    cout << c.get();
    return 0;
}