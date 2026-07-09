#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};

    reverse(v.begin(), v.end());
    reverse(v.begin(), v.end() - 1);

    for (auto s : v)
        cout << s << " ";
    cout << endl;
}