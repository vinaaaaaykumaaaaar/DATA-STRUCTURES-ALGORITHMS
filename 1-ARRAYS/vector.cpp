#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void declare_and_initialize()
{
    vector<int> v;
    int size;
    cin >> size;
    int a;

    for (int i = 0; i < size; i++)
    {
        cin >> a;
        v.push_back(a);
    }

    for (auto x : v)
        cout << x << " ";
    cout << endl;
}

void delete_using_erase()
{
    vector<int> v = {1, 2, 3, 4, 5};

    int d;
    cin >> d;

    v.erase(find(v.begin(), v.end(), d));

    for (auto x : v)
        cout << x << " ";
    cout << endl;
}

int main()
{
}