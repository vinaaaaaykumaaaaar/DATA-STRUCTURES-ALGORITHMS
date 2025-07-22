#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {4, 5, 2, 10, 8};

    vector<int> v1(v.size());

    stack<int> s;

    for (int i = 0; i < v.size(); i++)
    {

        while (!s.empty() && s.top() >= v[i])
            s.pop();

        v1[i] = s.empty() ? -1 : s.top();
        s.push(v[i]);
    }

    for (auto x : v1)
        cout << x << endl;

    return 0;
}