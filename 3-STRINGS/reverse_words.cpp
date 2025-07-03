/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

/*
Problem:
   Given an input string s, reverse the order of the words.A word is
   defined as a sequence of non-space characters. The words in s will
   be separated by at least one space.Return a string of the words in
   reverse order concatenated by a single space.Constraints:
   \(1<=s.length()<=10^{4}\)s contains English letters (upper-case and lower-case),
   digits, and spaces ' '.There will be at least one word in s
   The words in s will be separated by at least one space.The returned
   string should not contain leading or trailing spaces.Words in the
   returned string should be separated by a single space.

Examples:
   Example 1:
       Input: s = "the sky is blue"Output: "blue is sky the"
   Example 2:
       Input: s = "  hello world  "Output: "world hello"
       Explanation: Your reversed string should not contain leading or trailing spaces
   Example
       3:Input: s = "a good   example"Output: "example good a"
       Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string reverseWords(string s)
{
    int left = 0, right = s.length() - 1;
    string temp = "", ans = "";

    while (left <= right)
    {
        char c = s[left];
        if (c != ' ')
        {
            temp += c;
        }
        else if (c == ' ')
        {
            if (ans != "")
            {
                ans = temp + " " + ans;
            }
            else
            {
                ans = temp;
            }
            temp = "";
        }
        left++;
    }

    if (temp != "")
    {
        if (ans != "")
            ans = temp + " " + ans;
        else
            ans = temp;
    }

    return ans;
}

int main()
{

    string name = "i am good boy";
    cout << reverseWords(name) << endl;

    return 0;
}