#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> a = {2, 2, 3, 3, 1, 2};

    int c = 0, e;

    for (int i = 0; i < a.size(); i++)
    {
        if (c == 0)
            e = a[i], ++c;
        else if (a[i] == e)
            ++c;
        else
            --c;
    }

    c = 0;

    int n = (a.size() / 2) + 1;
    cout << n << endl;

    for (int i = 0; i < a.size(); ++i)
    {

        if (a[i] == e)
            c++;
    }

    if (c >= n)
        cout << "majority element : " << e << endl;
    else
        cout << "no majority" << endl;
}