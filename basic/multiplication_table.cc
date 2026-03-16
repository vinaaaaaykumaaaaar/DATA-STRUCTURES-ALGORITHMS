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
    void solFunction(int n)
    {
        int i = 1;
        
        while(i<11)
        {
            cout << n << " * " << i << " = " << n * i << endl;
            i++;
        }
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
    int input;

    while (T--)
    {
        cin >> input;
        sol.solFunction(input);
    }
}