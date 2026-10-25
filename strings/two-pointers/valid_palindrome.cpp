#include <iostream>
#include <string>

using namespace std;

char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

bool is_alphaNumeric(char c)
{
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9');
}

bool is_palindrome(const string &s)
{
    int left = 0, right = s.size() - 1;

    while (left < right)
    {
        while (left < right && !is_alphaNumeric(s[left]))
            left++;

        while (left < right && !is_alphaNumeric(s[right]))
            right--;

        if (to_lower(s[left]) != to_lower(s[right]))
            return false;

        left++, right--;
    }

    return true;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";

    if (is_palindrome(s))
        cout << "palindrome" << "\n";
    else
        cout << "not a palindrome" << "\n";

    return 0;
}