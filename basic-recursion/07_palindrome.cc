#include <iostream>
#include <string>

using namespace std;

bool palindrome_string(string text, int inital_point, int end_point)
{
    if (inital_point >= end_point)
        return true;
    else if (text[inital_point] != text[end_point])
        return false;

    return palindrome_string(text, inital_point + 1, end_point - 1);
}

int main()
{
    string text = "level";

    if (palindrome_string(text, 0, text.size() - 1))
        cout << "palindrome" << endl;
    else
        cout << "not a palindrome" << endl;

    return 0;
}