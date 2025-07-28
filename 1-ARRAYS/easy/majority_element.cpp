/*

Find the Majority Element that occurs more than N/2 times

Problem Statement: Given an array of N integers, write a program to return an element that occurs
more than N/2 times in the given array. You may consider that such an element always exists in the array.

Examples

Example 1:
Input Format: N = 3, nums[] = {3,2,3}
Result: 3
Explanation: When we just count the occurrences of each number and compare with half of the size of the array, you will get 3 for the above solution.

Example 2:
Input Format:  N = 7, nums[] = {2,2,1,1,1,2,2}

Result: 2

Explanation: After counting the number of times each element appears and comparing it with half of array size, we get 2 as result.

Example 3:
Input Format:  N = 10, nums[] = {4,4,2,4,3,4,4,3,2,4}

Result: 4

*/

#include <bits/stdc++.h>

using namespace std;

void brute_force(vector<int> &a)
{
    // TC -> O(n^2);
    // SC -> O(1);

    int majority = a.size() / 2;

    int ans = -1;

    for (int i = 0; i < a.size(); i++)
    {
        int count = 1;
        for (int j = i + 1; j < a.size(); j++)
        {
            if (a[i] == a[j])
                ++count;

            if (count > majority)
            {
                ans = a[i];
            }
        }
    }

    cout << ans << endl;
}

void better(vector<int> &a)
{
    // TC -> O(nlogn);
    // SC -> O(n);

    unordered_map<int, int> elements_frequency;
    int majority = a.size() / 2;
    int ans = -1;

    for (int i = 0; i < a.size(); i++)
    {
        elements_frequency[a[i]]++;
    }

    for (auto element : elements_frequency)
    {
        if (element.second > majority)
        {
            ans = element.first;
        }
    }

    cout << ans << endl;
}

void optimal(vector<int> &a)
{

    // Moore’s Voting Algorithm

    // TC -> O(n);
    // SC -> O(1);

    int majority = a.size() / 2;
    int count = 0;
    int ans = -1;

    for (int i = 0; i < a.size(); i++)
    {
        if (count == 0)
        {
            ++count;
            ans = a[i];
        }
        else if (a[i] == ans)
        {
            ++count;
        }
        else
        {
            --count;
        }
    }

    cout << ans << endl;
}

int main()
{

    vector<int> a = {3, 2, 3};
    vector<int> b = {2, 2, 1, 1, 1, 2, 2};
    vector<int> c = {4, 4, 2, 4, 3, 4, 4, 3, 2, 4};

    vector<vector<int>> test_cases = {a, b, c};

    cout << "-----------------------------------------------------------------" << endl;

    // Brute force approach test case
    cout << "--------------------- B R U T E - F O R C E ---------------------" << endl;
    for (auto test_case : test_cases)
    {
        brute_force(test_case);
    }

    // Better approach test case
    cout << "-------------------------- B E T T E R --------------------------" << endl;
    for (auto test_case : test_cases)
    {
        better(test_case);
    }

    // Optimal approach test case
    cout << "------------------------  O P T I M A L  ------------------------" << endl;
    for (auto test_case : test_cases)
    {
        optimal(test_case);
    }

    cout << "-----------------------------------------------------------------" << endl;

    return 0;
}