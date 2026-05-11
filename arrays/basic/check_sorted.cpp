#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> a = {5, 4, 6, 7, 8};

    bool flag = true;
    int j = 1;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > a[j])
        {
            flag = false;
            break;
        }

        j++;
    }

    cout << flag << endl;
}
