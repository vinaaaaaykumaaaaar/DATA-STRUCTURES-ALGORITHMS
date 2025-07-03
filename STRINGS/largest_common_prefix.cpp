/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

/*
Problem Statement:

    Write a function to find the longest common prefix string amongst an array of strings.
    If there is no common prefix, return an empty string "".

Key Concepts:

    Prefix: A prefix of a string is a substring that occurs at the beginning of the string.
    Common Prefix: A common prefix among a set of strings is a string that is a prefix to all of them.
    Longest Common Prefix (LCP): The longest string that is a common prefix to all the strings in the input array.

Example Cases:

    Input: strs = ["flower","flow","flight"]
    Output: "fl"
    Explanation: "fl" is the longest string that is a prefix to all three input strings.

    Input: strs = ["dog","racecar","car"]
    Output: ""
    Explanation: There is no common prefix among the input strings.

    Input: strs = ["geeksforgeeks", "geeks", "geek", "geezer"]
    Output: "gee"
    Explanation: "gee" is the longest common prefix.
*/

/*
Approaches:
    Several approaches can be used to solve the Longest Common Prefix problem:

    Horizontal Scanning: The first string is compared with the second string, and the common prefix is found. That prefix is compared with the third string, and so on.
    Vertical Scanning: The first character of all strings is compared, then the second character, continuing until a mismatch occurs or the shortest string ends.
    Divide and Conquer: The array of strings is recursively divided, and the LCP of the subarrays is found, then the results are merged.
    Binary Search: This approach involves finding the shortest string length and using binary search to determine the LCP length.
*/

#include <iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

std::string longestCommonPrefix(std::vector<std::string> &s)
{
 
    if (s.empty())
    {
        return ""; // Handle empty input array
    }

    string ans = "";

    for(int i=0 ; i<s[0].length(); i++)
    {
        char c = s[0][i];
        for(int j=1 ; j<s.size(); j++)
        {
            if(s[j][i] != c || i>s[j].length())
            {
                return s[0].substr(0,i);
            }
            
        }
    }
    // If the entire first string is a common prefix, return it
    return s[0];
}

int main()
{

    vector<string> strs = {"flower","flow","flight"};
    vector<string> name = {"geeksforgeeks", "geeks", "geek", "geezer"};
    cout << longestCommonPrefix(strs) << endl;
    cout << longestCommonPrefix(name) << endl;

    return 0;
}
