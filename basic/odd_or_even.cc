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
    string solFunction(int n)
    {
        if (n%2 == 0)
            return "even";
        else
            return "odd";
    }
};

// main function

int main()
{
    Solution sol;

    int number;
    cin >> number;

    cout << sol.solFunction(number) << endl;

    cin >> number;

    cout << sol.solFunction(number) << endl;
}