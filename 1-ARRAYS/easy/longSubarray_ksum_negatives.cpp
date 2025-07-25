/*


Longest Subarray with sum K | [Postives and Negatives]

Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.

Examples

Example 1:
Input Format: N = 3, k = 5, array[] = {2,3,5}
Result: 2
Explanation: The longest subarray with sum 5 is {2, 3}. And its length is 2.

Example 2:
Input Format: N = 3, k = 1, array[] = {-1, 1, 1}
Result: 3
Explanation: The longest subarray with sum 1 is {-1, 1, 1}. And its length is 3.


*/

#include <bits/stdc++.h>

using namespace std;

void brute_force(vector<int> a, int k)
{

    // tc --> O(n^2)

    // sc --> O(1);

    int m = 0;

    for (int i = 0; i < a.size(); i++)
    {
        int sum = 0;
        int count = 0;
        for (int j = i; j < a.size(); j++)
        {
            sum += a[j];
            count++;

            if (sum == k)
            {
                m = max(count, m);
                break;
            }
        }
    }

    cout << m << endl;
}

void better(vector<int> a, int k)
{

    // tc-> O(n);
    // sc -> O(n);
    unordered_map<int, int> m;
    int mx = 0, sum = 0;

    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];

        if (sum == k)
            mx = max(mx, i + 1);

        int rem = sum - k;

        if (m.find(rem) != m.end())
        {
            mx = max(mx, i - m[rem]);
        }

        if (!(m.find(sum) != m.end()))
        {
            m[sum] = i;
        }
    }

    cout << mx << endl;
}

int main()
{

    vector<int> a = {2, 3, 5};
    vector<int> b = {-1, 1, 1};

    cout << "-----------------------------------------------------------------" << endl;

    // Brute force approach test case
    cout << "--------------------- B R U T E - F O R C E ---------------------" << endl;
    brute_force(a, 5);
    brute_force(b, 1);

    // Better approach test case
    cout << "-------------------------- B E T T E R --------------------------" << endl;
    better(a, 5);
    better(b, 1);
    cout << "-----------------------------------------------------------------" << endl;

    return 0;
}