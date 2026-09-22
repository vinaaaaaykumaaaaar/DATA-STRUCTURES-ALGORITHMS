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

void resursion()
{
    int rem = 0;
    int rev = 1;
}

bool palindrome(int n, int rev, int temp)
{
    if (temp == 0)
    {
        return rev == n;
    }

    int rem = temp % 10;
    rev = rev * 10 + rem;

    temp = temp / 10;

    return palindrome(n, rev, temp);
}

void solve()
{
    int n = 121;

    if (palindrome(n, 0, n))
        cout << "palindrome" << endl;
    else
        cout << "not a palindrome" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}