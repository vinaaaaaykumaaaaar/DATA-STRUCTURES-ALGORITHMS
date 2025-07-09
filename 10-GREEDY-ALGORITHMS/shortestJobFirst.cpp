#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 shortest first algorithm
  - scheduling policy that selects the waiting process with the smallest exuction time to execute first
*/

int main()
{
    vector<int> p = {4, 3, 7, 1, 2};
    sort(p.begin(), p.end());

    int wt = 0, t = 0;

    for (int i = 0; i < p.size(); i++)
    {
        wt += t;
        t += p[i];
    }

    cout << wt / p.size() << endl;
}