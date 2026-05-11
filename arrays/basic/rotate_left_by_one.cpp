#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};

    int n = a[0];

    for (int i = 1; i < a.size(); i++)
    {
        a[i - 1] = a[i];
    }

    a[a.size() - 1] = n;

    for (auto x : a)
        cout << x << " ";
}