#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {1, 0, 1, 1, 0, 1, 0};
    vector<int> p(v.size() + 1);

    // pre computation
    p[0] = 0;

    for (int i = 0; i < v.size(); i++)
    {
        p[i + 1] = v[i] + p[i];
    }

    for (auto x : p)
        cout << x << " ";
    cout << endl;

    int l, r;
    cin >> l >> r;
    cout << p[r + 1] - p[l] << endl;

    return 0;
}