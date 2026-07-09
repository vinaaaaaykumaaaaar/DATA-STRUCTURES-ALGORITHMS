#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 0, 2, 3, 0, 4, 0, 1};

    int j = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0)
        {
            swap(v[j], v[i]);
            i++, j++;
        }
        }
}