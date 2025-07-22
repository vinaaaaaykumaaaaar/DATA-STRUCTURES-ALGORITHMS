#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{

    vector<int> v = {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};

    vector<int> v1(v.size());

    stack<int> s;

    for (int i = v.size() - 1; i >= 0; --i)
    {
        while (!s.empty() && s.top() <= v[i])
        {
            s.pop();
        }
        if (s.empty())
            v1[i] = -1;
        else
            v1[i] = s.top();

        s.push(v[i]);
    }

    for (auto x : v1)
        cout << x << endl;
}