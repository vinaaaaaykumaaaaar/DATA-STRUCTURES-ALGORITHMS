#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{

    vector<int> v = {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};

    vector<int> v1(v.size());

    stack<int> s;

    for (int i = 2 * v.size() - 1; i >= 0; --i)
    {
        while (!s.empty() && s.top() <= v[i % v.size()])
            s.pop();

        if (i < v.size())
            v1[i] = s.empty() ? -1 : s.top();
        s.push(v[i % v.size()]);
    }

    for (auto x : v1)
        cout << x << endl;
}