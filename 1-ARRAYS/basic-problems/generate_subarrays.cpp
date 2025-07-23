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

    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = i; j < a.size(); ++j)
        {
            for (int k = i; k <= j; ++k)
            {
                cout << a[k] << " ";
            }
            cout << endl;
        }
    }
}

void recursive(vector<int> &a, int s, int e)
{
}

int main()
{

    vector<int> a = {1, 2, 3};
    vector<int> b = {1, 2};
    vector<int> c = {1, 2, 3, 4};

    cout << "-----------------------------------" << endl;
    solve(a);
    cout << "-----------------------------------" << endl;
    solve(b);
    cout << "-----------------------------------" << endl;
    solve(c);
    cout << "-----------------------------------" << endl;
    return 0;
}