#include <iostream>
using namespace std;

long long reverse_rec(long long num, long long rev)
{
    if (num == 0)
        return rev;
    return reverse_rec(num / 10, rev * 10 + (num % 10));
}

bool isPalindrome(int n)
{
    long long num = llabs((long long)n);

    if (num == 0)
        return true;

    long long rev = reverse_rec(num, 0);

    return num == rev;
}

int main()
{
    int n;
    cin >> n;
    cout << boolalpha << isPalindrome(n); // prints true / false
    return 0;
}