#include <iostream>
#include <vector>
using namespace std;

int main()
{

    std::vector<int> a = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 2};

    int n = a.size() - 1;

    int l = 0, h = n, m = 0;

    while (m <= h)
    {
        if (a[m] == 0)
            swap(a[m], a[l]), ++m, ++l;
        else if (a[m] == 1)
            ++m;
        else
            swap(a[h], a[m]), --h;
    }

    for (auto x : a)
        std::cout << x << " ";
    std::cout << std::endl;
    return 0;
}