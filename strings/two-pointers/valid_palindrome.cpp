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

    int write_index = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        char lowered = to_lower(s[i]);
        if (is_alphanumeric(lowered))
        {
            s[write_index] = lowered;
            write_index++;
        }
    }

    s.resize(write_index);

    if (is_palindrome(s))
        cout << "palindrome";
    else
        cout << "not a palindrome";

    return 0;
}