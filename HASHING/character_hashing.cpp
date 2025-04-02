#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    // pre-computation
    int hash[256] = {0};

    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i]] += 1;
    }

    int q;
    cin >> q;

    while (q--)
    {
        char c;
        cin >> c;

        cout << hash[c] << endl;
    }
}