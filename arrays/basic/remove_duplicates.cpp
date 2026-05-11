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

int main()
{
    vector<int> a = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    int j = 0;

    for (int i = 1; i < a.size(); i++)
    {
        debug(j, a[j]);
        if (a[i] != a[j])
        {
            ++j;
            swap(a[j], a[i]);
        }
    }

    for (int i = 0; i <= j; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}