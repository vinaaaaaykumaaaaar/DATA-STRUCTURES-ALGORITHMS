/*
Let's say I give you an array:

{5, 7, 1, 9, 1, 8}
and I ask you: "What's the sum of elements in a specific range [l..r]?"
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {5, 7, 1, 9, 1, 8};

    int l, r;
    cin >> l >> r;

    int ans = 0;

    for (int i = l; i <= r; i++)
    {
        ans += v[i];
    }

    cout << ans << "\n";

    return 0;
}