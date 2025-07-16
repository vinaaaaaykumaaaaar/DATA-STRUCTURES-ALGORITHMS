#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<pair<int, int>> s;

    // int arr[5] = {12, 15, 10, 5, 30};

    // for (int i = 0; i < 5; i++)
    // {
    //     s.push({arr[i], min(arr[i], s.top().first)});
    // }
    s.push({10, 20});
    cout << s.top().first << endl;
    cout << s.empty() << endl;
}