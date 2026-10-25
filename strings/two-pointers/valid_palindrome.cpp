#include <iostream>
#include <string>

using namespace std;

char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;

    return c;
}

bool is_alphanumeric(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        return true;
    return false;
}

bool is_palindrome(string duplicate)
{
    int left = 0, right = duplicate.size() - 1;

    while (left < right)
    {
        if (duplicate[left] != duplicate[right])
            return false;
        left++, right--;
    }

    return true;
}

int main()
{
    // Test case containing punctuation, spaces, and numbers
    string s = "A man, a plan, a canal: Panama";

    for (char &c : s)
        c = to_lower(c);

    string duplicate = "";

    for (int i = 0; i < s.size(); ++i)
    {
        // Updated to use the corrected alphanumeric check
        if (is_alphanumeric(s[i]))
        {
            duplicate += s[i];
        }
    }

    if (is_palindrome(duplicate))
        cout << "palindrome";
    else
        cout << "not a palindrome";

    return 0;
}