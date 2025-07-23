/*

Given an array of n integers. We need to reduce size of array to one.
We are allowed to select a pair of integers and remove the larger one of these two.
This decreases the array size by 1. Cost of this operation is equal to value of smallest
one. Find out minimum sum of costs of operations needed to convert the array into a single element.

Examples:

Input: arr[]= [4 ,3 ,2 ]
Output: 4
Explanation: Choose (4, 2) so 4 is removed, new array = {2, 3}. Now choose (2, 3) so 3 is removed.  So total cost = 2 + 2 = 4.

Input: arr[]=[ 3, 4 ]
Output: 3
Explanation: choose (3, 4) so cost is 3.

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

using namespace std;

void solve(vector<int> &a)
{
    int n = a.size() - 1;
    int cost = n * *min_element(a.begin(), a.end());
    cout << cost << endl;
}

int main()
{

    vector<int> a = {4, 3, 2};
    vector<int> b = {3, 4};

    cout << "--------------------------------" << endl;
    solve(a);
    cout << "--------------------------------" << endl;
    solve(b);
    cout << "--------------------------------" << endl;

    return 0;
}
