#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#include <climits>
#include <numeric>
#include <utility>
#include <functional>
#include <bitset>
#include <cstring>
using namespace std;
#define ll long long

#define debug(x) cerr << #x << " = " << (x) << "\n"
#define debugArr(a, n)                               \
    cerr << #a << " = [";                            \
    for (int i = 0; i < (n); i++)                    \
        cerr << (a)[i] << (i + 1 < (n) ? ", " : ""); \
    cerr << "]\n"
#define debugVec(v)        \
    cerr << #v << " = [";  \
    for (auto &i : v)      \
        cerr << i << ", "; \
    cerr << "]\n"

void count(vector<int> &arr)
{
    int c0 = 0, c1 = 0, c2 = 0;

    for (auto x = 0; x < arr.size(); x++)
    {
        if (arr[x] == 0)
            c0++;
        else if (arr[x] == 1)
            c1++;
        else
            c2++;
    }
    cout << c0 << " " << c1 << " " << c2 << endl;
    for (int i = 0; i < c0; i++)
        arr[i] = 0;
    for (auto x : arr)
        cout << x << " ";
    cout << endl;

    for (int i = c0; i < c0 + c1; i++)
        arr[i] = 1;
    for (auto x : arr)
        cout << x << " ";
    cout << endl;
    for (int i = c0 + c1; i < arr.size(); i++)
        arr[i] = 2;

    for (auto x : arr)
        cout << x << " ";
    cout << endl;
}
void solve()
{
    vector<int> arr = {0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 0, 1};

    count(arr);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}