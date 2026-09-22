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

void print_n(int n)
{
    if (n <= 0)
        return;

    cout << n << endl;
    print_n(n - 1);
}

void solve()
{
    print_n(10);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}