#include <iostream>
#include <string>

bool palindrome(std::string word, int start, int end)
{
    if (word.length() <= 1)
        return true;

    if (start >= end)
        return true;

    if (word[start] == word[end])
        ++start, --end;
    else
        return false;

    return palindrome(word, start, end);
}

int main()
{
    std::string word = "";

    std::cout << "Enter the word" << std::endl;
    std::cin >> word;

    if (palindrome(word, 0, word.size() - 1))
        std::cout << "yes the word is palindrome" << std::endl;
    else
        std::cout << "no the word is not a palindrome" << std::endl;

    return 0;
}