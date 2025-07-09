#include <iostream>
#include <vector>

int helper(int n, std::vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = helper(n - 1, dp) + helper(n - 2, dp);

    return dp[n];
}

int fibMemoization(int n)
{
    std::vector<int> dp(n + 1, -1);
    int res = helper(n, dp);
    return res;
}

int main()
{
    int n = 0;
    std::cin >> n;

    std::cout << fibMemoization(n) << std::endl;
    return 0;
}