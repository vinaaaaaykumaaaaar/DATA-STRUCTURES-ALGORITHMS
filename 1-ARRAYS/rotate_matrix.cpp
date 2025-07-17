#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <list>

using namespace std;

void solve(vector<int> &a)
{

    // formula is a[i]a[j] -> a[j][n-1-i];

    // transpose -> reverse
    // formula is if ( i != j ) swap(a[i][j] , a[j][i])
}

void optimal(vector<int> &a)
{
}

int main()
{

    vector<int> a = {3, 1, -2, -5, 2, -4};
    int n, m, i, k;

    solve(a);
    optimal(a);
    return 0;
}

// 3 1 -2 -5 2 -4 -> -2 3 -5 1 -4 2