/*
Pair Cube Count
Given n, count all 'a' and 'b' that satisfy the condition a^3 + b^3 = n. Where (a, b) and (b, a) are considered two different pairs

Examples: 

Input: n = 9
Output: 2
Explanation: 1^3 + 2^3 = 9 and 2^3 + 1^3 = 9

Input: n = 28
Output: 2
Explanation: 1^3 + 3^3 = 28 and 3^3 + 1^3 = 28
*/

#include <iostream>
#include <math.h>

using namespace std;

int countPairs(int n) {
    int count = 0;

    // Check for each number 1 to cbrt(n)
    for (int i = 1; i <= cbrt(n); i++)  {
        int cube_of_a = i*i*i;

        int diff = n - cube_of_a;

        int cube_diff = cbrt(diff);

        if(cube_diff*cube_diff*cube_diff == diff)
        {
            count++;
        }
    }

    return count;
}

int main() {
 		int n = 28;
        cout << countPairs(n) <<"\n";

    return 0;
}