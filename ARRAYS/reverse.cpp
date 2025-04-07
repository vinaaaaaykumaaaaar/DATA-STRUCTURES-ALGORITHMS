#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v1 = v;

    int i = 0, j = v.size() - 1;

    while (i < j)
    {
        swap(v[i], v[j]);
        i++, j--;
    }

    for (auto x : v)
        cout << x << endl;
}