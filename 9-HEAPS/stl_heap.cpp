#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    make_heap(v.begin(), v.end());

    for (auto x : v)
        cout << x << " ";
    cout << endl;
}