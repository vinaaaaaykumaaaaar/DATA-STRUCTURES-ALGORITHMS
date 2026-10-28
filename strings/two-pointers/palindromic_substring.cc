#include <iostream>
#include <string>

using namespace std;

bool palindrome(const string s, int left, int right)
{
    while (left < right)
    {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

int main()
{
    string s = "abc";
    int count = 0;

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            if (palindrome(s, i, j))
                count++;
        }
    }

    cout << count << endl;

    return 0;
}