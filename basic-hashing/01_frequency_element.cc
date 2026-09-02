#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    vector<int> arr = {10, 5, 10, 15, 10, 5};
    map<int, int> hash;

    for (auto a : arr)
        hash[a]++;

    for (auto x : hash)
        cout << x.first << " " << x.second << endl;

    return 0;
}