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

    if (a.size() <= 1)
    {
        cout << "sorted" << endl;
        return;
    }

    for (auto i = 1; i < a.size(); i++)
        if (a[i] < a[i - 1])
        {
            cout << "not sorted" << endl;
            return;
        }

    cout << "sorted" << endl;
}

int main()
{

    vector<int> a = {10, 20, 30, 40, 50};
    vector<int> v = {90, 80, 100, 70, 40, 30};

    solve(a);
    solve(v);
    return 0;
}