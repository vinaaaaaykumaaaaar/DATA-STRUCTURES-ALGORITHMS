/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.


Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false



Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <map>

class Solution
{
public:
    static inline bool isValid(std::string s)
    {
        std::stack<char> st;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else
            {
                if (st.empty())
                    return false;
                if ((s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '[') || (s[i] == '}' && st.top() == '{'))
                {
                    st.pop();
                }
                else
                    return false;
            }
        }

        return st.empty();
    }
};

int main()
{

    Solution sol;
    std::map<std::string, int> test_cases;
    test_cases["()"] = 1;
    test_cases["()[]{}"] = 1;
    test_cases["(]"] = 0;
    test_cases["([])"] = 1;
    test_cases["([)]"] = 0;

    for (auto test_data : test_cases)
    {
        if (test_data.second == sol.isValid(test_data.first))
        {
            std::cout << "test case passed successfully" << std::endl;
        }
        else
        {
            std::cout << "test case failed" << std::endl;
        }
    }
}