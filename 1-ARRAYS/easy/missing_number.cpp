/*
Find the missing number in an array

Problem Statement: Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N.
Find the number(between 1 to N), that is not present in the given array.

Examples

Example 1:
Input Format: N = 5, array[] = {1,2,4,5}
Result: 3
Explanation: In the given array, number 3 is missing. So, 3 is the answer.

Example 2:
Input Format: N = 3, array[] = {1,3}
Result: 2
Explanation: In the given array, number 2 is missing. So, 2 is the answer.

*/

#include <bits/stdc++.h>

using namespace std;

void brute_force(vector<int> &a)
{

    // tc -> O(n);
    // sc -> O(1);
    int missing = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != (i + 1))
        {
            missing = i + 1;
            break;
        }
    }

    cout << missing << endl;
}

void better(vector<int> &a)
{

    // tc -> O(n);
    // sc->O(1);

    int OriginalSum = ((a.size() + 1) * (a.size() + 2)) / 2;

    int sum = 0;
    int i = 0;
    while (i < a.size())
    {
        sum += a[i];
        i++;
    }

    cout << OriginalSum - sum << endl;
}

void optimal(vector<int> &a)
{

    // Xor :TODO
}

int main()
{

    vector<int> a = {1, 2, 4, 5};
    vector<int> b = {1, 3};
    vector<int> c = {1, 2, 3, 5, 6, 7};

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
