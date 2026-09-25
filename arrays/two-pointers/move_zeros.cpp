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

void move_zeros(vector<int> &arr)
{
    int length = arr.size();
    int writeIndex = 0;

    for (int readIndex = 0; readIndex < length; readIndex++)
    {
        if (arr[readIndex] != 0)
        {
            swap(arr[readIndex], arr[writeIndex]);
            writeIndex++;
        }
    }
}

void solve()
{
    vector<int> arr = {0, 1, 0, 3, 12};
    move_zeros(arr);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}