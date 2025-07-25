/*

Sort an array of 0s, 1s and 2s

Problem Statement: Given an array consisting of only 0s, 1s, and 2s.
 Write a program to in-place sort the array without using inbuilt sort functions.
 ( Expected: Single pass-O(N) and constant space )

Examples
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Input: nums = [2,0,1]
Output: [0,1,2]

Input: nums = [0]
Output: [0]
*/

#include <bits/stdc++.h>
using namespace std;

void bruteforce(vector<int> a)
{

    // tc -> O(nlogn);
    // sc -> O(1);
    sort(a.begin(), a.end());

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void better(vector<int> a)
{
    map<int, int> m;
    for (auto x : a)
        m[x]++;

    int i = 0;
    while (m[0])
    {
        a[i] = 0;
        m[0]--;
        i++;
    }
    while (m[1])
    {
        a[i] = 1;
        m[1]--;
        i++;
    }
    while (m[2])
    {
        a[i] = 2;
        m[2]--;
        i++;
    }

    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
}

void optimal(vector<int> a)
{
    int l = 0, m = 0, h = a.size() - 1;

    while (m <= h)
    {
        if (a[m] == 0)
        {
            swap(a[l], a[m]);
            l++;
            m++;
        }
        else if (a[m] == 1)
            m++;
        else

        {
            swap(a[m], a[h]);
            h--;
        }
    }

    for (auto x : a)
        cout << x << " ";
    cout << endl;
}

int main()
{
    vector<int> a = {2, 0, 2, 1, 1, 0};
    vector<int> b = {2, 0, 1};
    vector<int> c = {0};

    cout << "----------------------------------------------------" << endl;

    bruteforce(a);
    bruteforce(b);
    bruteforce(c);

    cout << "----------------------------------------------------" << endl;

    better(a);
    better(b);
    better(c);

    cout << "----------------------------------------------------" << endl;
    optimal(a);
    optimal(b);
    optimal(c);
}