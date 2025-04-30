#pragma GCC optimize("03")
#pragma GCC target ("sse4")

#include<bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
  
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;\

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

ll a[7] = {2,2,3,3,1,2,2};

void naive_solution()
{
    // time complexity -> O(n^2)
    // space complexity -> O(1)

    
    for(int i=0;i<7;i++)
    {
        int c=0;
        for(int j=0;j<7;j++)
         {
             if(a[j] == a[i])
                 c++;
         }
         if(c > 7/2)
             cout<<"Majority Element "<<a[i]<<endl;
     }
      
}

void better_solution()
{
    // time complexity ->
    // space complexity ->
    map<int,int> m = {};
    for(int i=0; i<7; i++)
        m[a[i]]++;

    for(auto x:m)
        if(x.second > 7/2)
            cout<<x.first<<" ";
    cout<<endl;

}

void optimal_solution()
{
    // time complexity ->
    // space complexity ->

}

int main()
{
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
            
//    naive_solution();
     better_solution();
    // optimal_solution();
                                      
    return 0;
}

