#include <bits/stdc++.h>
using namespace std;

// debug macro

void _debug_print() { cerr << endl; }

template <typename T, typename... Args>
void _debug_print(T t, Args... args)
{
    cerr << t << " ";
    _debug_print(args...);
}

#define debug(...)                             \
    do                                         \
    {                                          \
        cerr << "[" << #__VA_ARGS__ << "] = "; \
        _debug_print(__VA_ARGS__);             \
        cerr << endl;                          \
    } while (0)

// solution class

class Solution
{
public:
    int solFunction(int n , int m )
    {
        int q = n / m;
        // 1st possible closest number
        int n1 = m * q;

        // 2nd possible closest number
        int n2 = (n * m) > 0 ? (m * (q + 1)) : (m * (q - 1));

        // if true, then n1 is the required closest number
        if (abs(n - n1) < abs(n - n2))
            return n1;

        // else n2 is the required closest number
        return n2;
    }
};

// main function

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    int T = 1;
    // cin >> T;
    int n , m;

    while (T--)
    {
        cin >> n>>m;
        cout << sol.solFunction(n,m) << endl;
    }
}