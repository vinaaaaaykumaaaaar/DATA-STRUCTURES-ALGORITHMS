/*

Given an integer array arr[], find all the distinct elements of the given array.
 The given array may contain duplicates and the output should contain every element only once.

Examples:

Input: arr[] = [2, 2, 3, 3, 7, 5]
Output: [2, 3, 7, 5]
Explanation : After removing the duplicates 2 and 3 we get 2 3 7 5.

Input: arr[] = [1, 2, 3, 4, 5]
Output: [1, 2, 3, 4, 5]
Explanation : There doesn't exists any duplicate element.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <unordered_map>
#include <set>

using namespace std;

void solve(vector<int> &a)
{

    vector<int> b;
    sort(a.begin(), a.end()); // nlogn

    for (int i = 0; i < a.size(); i++) // n
    {
        if (i == 0 || (a[i] != a[i - 1]))
            b.push_back(a[i]);
    }

    a = b;

    for (auto x : a)
        cout << x << " ";
    cout << endl;

    // O(nlogn)
}

int main()
{

    vector<int> a = {2, 2, 10, 3, 3, 7, 5, 10};

    solve(a);
    return 0;
}