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

int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}

void solve()
{
    cout << factorial(4) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}