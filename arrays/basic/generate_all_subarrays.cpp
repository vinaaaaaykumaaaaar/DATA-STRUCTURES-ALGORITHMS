#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {1, 2, 3};

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i; j < a.size(); j++)
        {
            for (int k = i; k <= j; k++)
                cout << a[k] << " ";
            cout << endl;
        }
        cout << "\n";
    }
}