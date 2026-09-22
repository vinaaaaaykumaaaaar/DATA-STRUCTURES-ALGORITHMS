#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {5, 3, 8, 2, 4, 1};

    stack<int> st;

    for (int a : arr)
    {
        while (!st.empty() && st.top() >= a)
        {
            st.pop();
        }

        st.push(a);
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}