#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <limits>
#include <cassert>

using namespace std;

// ----- FAST IO -------------------------------------------------------
static auto _fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// ----- TYPE ALIASES --------------------------------------------------
using ll = long long;
using vl = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

// ----- SHORTCUT MACROS -----------------------------------------------
#define all(x)  (x).begin(), (x).end()
#define sz(x)   int((x).size())
#define pb      push_back
#define fi      first
#define se      second
#define FOR(i,a,b)  for(int i = (a); i <(b); ++i)
#define ROF(i,a,b)  for(int i = int(b) - 1; i >= (a); --i)

// ----- DEBUGGING (LOCAL ONLY)     ------------------------------------

#ifdef LOCAL
    #define dbg(...) __dbg(#__VA_ARGS__, __VA_ARGS__)
    template<typename T>
    void __dbg(const char* s, T&& x) {
        cerr << s << " = " << x << "\n";
    }
    template<typename T, typename... Ts>
    void __dbg(const char* s, T&& x, Ts&&... xs) {
         const char* comma = strchr(s + 1, ',');
         cerr.write(s, comma - s) << " = " << x << " | ";
         __dbg(comma + 1, xs...);
    }
    #else
        #define dbg(...) (void)0
    #endif

// ----- SOLVE ---------------------------------------------------------
void solve(){

}


int main(){
    int T = 1;
    // For multiple test cases, uncomment :
    // cin >> T;
    while (T--) solve();

    return 0;
}
