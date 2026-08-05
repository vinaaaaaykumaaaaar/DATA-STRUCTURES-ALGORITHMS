#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    vector<int> v = {1, 7, 3, 6, 5, 6, 6};

    vector<int> p(v.size());

    std::partial_sum(v.begin(), v.end(), p.begin() + 1);

    for (auto x : p)
        cout << x << " ";
    cout << endl;
}