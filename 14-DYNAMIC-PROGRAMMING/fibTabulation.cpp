#include <iostream>
#include <vector>

int fibTabulation(int n)
{
    if (n <= 1)
        return n;
    std::vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main()
{
    int n = 0;
    std::cin >> n;

    std::cout << fibTabulation(n) << std::endl;
}