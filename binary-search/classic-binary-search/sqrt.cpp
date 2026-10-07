#include <iostream>
#include <limits>

using namespace std;

int brute_force(int n) // O(n/2);
{
    int x = n / 2;

    int answer = 0;

    for (int i = 0; i < x; ++i)
    {
        if (i * i >= n)
        {
            answer = i;
        }
    }

    return answer;
}

int binary_search(int n)
{
    if (n < 2)
        return n;

    long long left = 1;
    long long right = n / 2;

    long long answer = 0;

    while (left <= right)
    {
        long long mid = left + (right - left) / 2;

        if (mid * mid <= n)
        {
            answer = mid;

            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return answer;
}

int main()
{
    int n = 8;

    // cout << brute_force(n) << endl;

    cout << binary_search(n) << endl;
    return 0;
}