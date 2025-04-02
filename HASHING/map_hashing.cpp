#include <iostream>
#include <map>
using namespace std;

/*
MAP -> pre-built data structure in "Standard Template Library"

*/

int main()
{

    int n;
    cin >> n;
    int arr[100];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // pre-computing
    map<int, int> hash;

    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    for (auto it : hash)
    {
        cout << it.first << "-->" << it.second << endl;
    }

    // int q;
    // cin >> q;
    // while (q--)
    // {
    //     int number;
    //     cin >> number;

    //     // fetch

    //     cout << hash[number] << endl;
    // }

    return 0;
}