#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(const string s, int left, int right)
{
    while (left < right)
    {
        if (s[left] != s[right])
            return false;
        left++, right--;
    }

    return true;
}

bool palindrome_modified(const string s)
{
    int left = 0, right = s.size() - 1;

    while (left < right)
    {
        if (s[left] != s[right])
            return (is_palindrome(s, left + 1, right)) || (is_palindrome(s, left, right - 1));

        left++, right--;
    }
    return true;
}

int main()
{
    string s = "leveal";

    cout << palindrome_modified(s) << endl;

    return 0;
}