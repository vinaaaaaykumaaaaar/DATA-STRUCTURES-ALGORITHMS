
#include <bits/stdc++.h>
using namespace std;

bool res = false;

void findSubsequence(int ind, int sum, int k, vector<int> &cur,
                     vector<int> &arr)
{

    if (ind >= arr.size())
    {
        if (sum == k)
        {
            res = true;
            return;
        }

        return;
    }

    findSubsequence(ind + 1, sum += arr[ind], k, cur, arr);

    findSubsequence(ind + 1, sum -= arr[ind], k, cur, arr);
}

int main()
{
    vector<int> arr = {1, 2, 3};
    int k = 6;
    vector<int> cur;
    findSubsequence(0, 0, k, cur, arr);

    cout << res << endl;

    return 0;
}
