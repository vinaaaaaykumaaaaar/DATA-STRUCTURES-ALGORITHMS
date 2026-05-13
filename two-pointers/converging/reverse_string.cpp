/*
Given a string s, reverse the string. Reversing a string means rearranging the characters such that the first character becomes the last, the second character becomes second last and so on.

Examples:

Input: s = "GeeksforGeeks"
Output: "skeeGrofskeeG"
Explanation : The first character G moves to last position, the second character e moves to second-last and so on.

Input: s = "abdcfe"
Output: "efcdba"
Explanation: The first character a moves to last position, the second character b moves to second-last and so on. 
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input = "GeeksforGeeks";

    int left = 0 , right = input.length() - 1; 

    while(left <= right)
    {
        swap(input[left] , input[right]);
        left++ , right--;
    }

    cout<<input<<endl;
}