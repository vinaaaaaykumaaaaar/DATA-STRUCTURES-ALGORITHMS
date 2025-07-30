#include <iostream>
#include <string>
#include <algorithm>

std::string reverse(std::string word, int start, int end)
{
    if (word.size() <= 1)
    {
        return word;
    }

    if (start >= end)
    {
        return word;
    }

    std::swap(word[start], word[end]);

    return reverse(word, start + 1, end - 1);
}

int main()
{
    std::string word = "";
    std::cout << "Enter the string" << std::endl;
    std::cin >> word;

    std::cout << reverse(word, 0, word.size() - 1) << std::endl;

    return 0;
}