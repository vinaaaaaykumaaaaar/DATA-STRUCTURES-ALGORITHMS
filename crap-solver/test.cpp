
#include <bits/stdc++.h>
using namespace std;

// ========== DEBUG UTILITIES ==========

#ifdef LOCAL
// Generic printer for types that support operator<<
template <class T>
void _print(const T &x) { cerr << x; }

// Pair
template <class T, class U>
void _print(const pair<T, U> &p) {
    cerr << "{";
    _print(p.first);
    cerr << ", ";
    _print(p.second);
    cerr << "}";
}

// Vector
template <class T>
void _print(const vector<T> &v) {
    cerr << "[";
    bool first = true;
    for (const auto &e : v) {
        if (!first) cerr << ", ";
        first = false;
        _print(e);
    }
    cerr << "]";
}

// You can add more overloads later for set, map, etc.

#define debug(x) cerr << #x << " = ", _print(x), cerr << " (line " << __LINE__ << ")\n"
#else
#define debug(x)
#endif

// ========== CORE SOLUTION STRUCTURE ==========

void solve() {
    // 1) Read input
    // 2) Apply logic
    // 3) Print output

    // Example skeleton:
    // int n;
    // cin >> n;
    // vector<int> a(n);
    // for (int i = 0; i < n; ++i) cin >> a[i];
    // debug(a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    auto __start_time = chrono::high_resolution_clock::now();
#endif

    int T = 1;
    // If multiple testcases, uncomment:
    // cin >> T;

    while (T--) {
        solve();
    }

#ifdef LOCAL
    auto __end_time = chrono::high_resolution_clock::now();
    auto __duration = chrono::duration_cast<chrono::milliseconds>(__end_time - __start_time).count();
    cerr << "Time: " << __duration << " ms\n";
#endif

    return 0;
}
