/*

Count Good numbers
A digit string is good if the digits (0-indexed) at even indices are even and digits at odd indices are prime ( 2 , 3 , 5 or 7 ).

For example, "4562" is good because the digits (4 and 6) at even positions are even
and the digits (5 and 2) at odd positions are prime. However, "3245" is not good.

Given an integer N , return the total number of good digit strings of length N.
Since the answer may be too large, return it modulo 109 + 7.

Note : A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

Example 1:

Input:
N = 1
Output:
5
Explanation:
The good digit string of length of 1 are "0" , "2" , "4" ,"6" and "8".

Example 2:

Input:
N = 3
Output:
100


Your Task:

You don't need to read input or print anything. Your task is to complete the function countGoodNumbers()
 which takes an integer N as inputs returns the total number of good digit strings of length N . As this result can be very large return the result under modulo 109+7.

Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 1015


*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
}