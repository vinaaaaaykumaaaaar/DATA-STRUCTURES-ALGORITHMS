#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    vector<int> v = {3, -5, 12, 0, 7, -2, 19, 4, -8, 25};

    vector<int> p(v.size());

    std::partial_sum(v.begin(), v.end(), p.begin() + 1);

    for (auto x : p)
        cout << x << " ";
    cout << endl;
}