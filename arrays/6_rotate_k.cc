#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    int k = 3;

    reverse(v.begin(), v.end());
    reverse(v.begin(), v.end() - k);

    for (auto x : v)
        cout << x << " ";
    cout << endl;
}