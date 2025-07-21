#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <unordered_map>

using namespace std;

void rtoi(string &s)
{
    unordered_map<char, int> r;
    r['I'] = 1;
    r['V'] = 5;
    r['X'] = 10;
    r['L'] = 50;
    r['C'] = 100;
    r['D'] = 500;
    r['M'] = 1000;

    int a = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        if (r[s[i]] < r[s[i + 1]])
            a -= r[s[i]];
        else
            a += r[s[i]];
    }

    cout << a << endl;
}

int main()
{

    string r = "IVII";
    rtoi(r);
}