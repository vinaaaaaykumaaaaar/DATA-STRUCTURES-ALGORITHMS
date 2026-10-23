#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {5, 7, 1, 9, 1, 8};
    vector<int> p(v.size() + 1);

    // pre computation
    p[0] = 0;
    for (int i = 0; i < v.size(); i++)
    {
        p[i + 1] = p[i] + v[i];
    }

    for (auto x : p)
        cout << x << " ";
    cout << endl;

    int l, r;
    cin >> l >> r;

    cout << p[r + 1] - p[l] << "\n";

    return 0;
}