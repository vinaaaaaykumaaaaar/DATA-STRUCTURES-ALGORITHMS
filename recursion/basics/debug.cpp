#include <iostream>

void printIndent(int depth)
{
    for (int i = 0; i < depth; ++i)
        std::cout << "  ";
}

long long factorial(int n, int depth = 0)
{
    printIndent(depth);
    std::cout << "-> CALL factorial(" << n << ")"
              << "  [depth=" << depth
              << ", &n=" << &n << "]\n";

    if (n <= 1)
    {
        printIndent(depth);
        std::cout << "<- RETURN 1 (base case)\n";
        return 1;
    }

    long long subResult = factorial(n - 1, depth + 1);
    long long result = n * subResult;

    printIndent(depth);
    std::cout << "<- RETURN " << n << " * " << subResult
              << " = " << result << "\n";
    return result;
}

int main()
{
    int n = 5;
    std::cout << "Computing " << n << "! using recursion\n\n";
    long long ans = factorial(n);
    std::cout << "\nFinal: " << n << "! = " << ans << "\n";
}