/*
Longest Subarray with given Sum K(Positives)

Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.

Examples

Example 1:
Input Format: N = 3, k = 5, array[] = {2,3,5}
Result: 2
Explanation: The longest subarray with sum 5 is {2, 3}. And its length is 2.

Example 2:
Input Format: N = 5, k = 10, array[] = {2,3,5,1,9}
Result: 3
Explanation: The longest subarray with sum 10 is {2, 3, 5}. And its length is 3.

*/

#include <bits/stdc++.h>

using namespace std;

void brute_force(vector<int> a, int k)
{

    // tc -> O(n^2);
    // sc -> O(1);

    int m = 0;

    for (int i = 0; i < a.size(); i++)
    {
        int sum = 0;
        int count = 0;
        for (int j = i; j < a.size(); j++)
        {
            sum += a[j];
            ++count;
            if (sum == k)
            {
                m = max(m, count);
                break;
            }
        }
    }

    cout << m << endl;
}

// prefix sum (hashing)

void better(vector<int> a, int k)
{
    map<int, int> m;

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

        m[sum] = i;
    }

    cout << mx << endl;
}

void optimal(vector<int> &a)
{
}

int main()
{

    vector<int> a = {2, 3, 5};
    vector<int> b = {2, 3, 1, 1, 1, 1, 2, 5, 1, 9};

    vector<vector<int>> test_cases = {a, b};

    cout << "-----------------------------------------------------------------" << endl;

    // Brute force approach test case
    cout << "--------------------- B R U T E - F O R C E ---------------------" << endl;
    brute_force(a, 5);
    brute_force(b, 10);

    // Better approach test case
    cout << "-------------------------- B E T T E R --------------------------" << endl;
    better(a, 5);
    better(b, 10);

    // Optimal approach test case
    cout << "------------------------  O P T I M A L  ------------------------" << endl;
    for (auto test_case : test_cases)
    {
        optimal(test_case);
    }

    cout << "-----------------------------------------------------------------" << endl;

    return 0;
}

/*



#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        long long rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}



*/