#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()

{
    string n = "aaaaaaaaaaaa";

    unordered_map<char, int> m;

    for (int i = 0; i < n.size(); i++)
    {

        m[n[i]]++;
    }

    char k;
    cin >> k;
    cout << m[k];
}