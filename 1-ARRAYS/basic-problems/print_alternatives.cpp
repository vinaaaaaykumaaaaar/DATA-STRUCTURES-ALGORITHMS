#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <unordered_map>

using namespace std;

void solve(vector<int> &a)
{
    for (int i = 0; i < a.size(); i += 2)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{

    vector<int> a = {-5, 1, 4, 2, 12};

    solve(a);
    return 0;
}