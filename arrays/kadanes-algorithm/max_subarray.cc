#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    vector<int> a = {5, 4, -1, 7, 8};

    int maxSum = INT_MIN;

    for (int i = 0; i < a.size(); i++)
    {
        int curSum = 0;
        for (int j = i; j < a.size(); j++)
        {
            curSum += a[j];
            maxSum = max(maxSum, curSum);
        }
    }

    cout << maxSum << endl;

    return 0;
}