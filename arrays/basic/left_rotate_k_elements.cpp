#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    // ->O(n) + O(n) +O(n)  = O(n)
    reverse(a.begin(), a.begin() + k);
    reverse(a.begin() + k, a.end());
    reverse(a.begin(), a.end());

    for (auto x : a)
        cout
            << x << " ";
}