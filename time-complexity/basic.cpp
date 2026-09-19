#include <iostream>
#include <vector>
using namespace std;

// fundamental idea is -> 1 operation = 1 simple C++ statement: +, -, *, /, =, if, a[i]

int main()
{
    int n;
    vector<int> arr;

    // linear time complexity
    int sum = 0; // 1 op
    for (int i = 0; i < n; i++)
    {                  // n+1 checks
        sum += arr[i]; // n ops
    }
}