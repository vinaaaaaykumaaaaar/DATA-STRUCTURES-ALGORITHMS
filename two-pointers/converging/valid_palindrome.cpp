/*
Given a string s, the task is to check if it is palindrome or not.

Example:

Input: s = "abba"
Output: true
Explanation: s is a palindrome

Input: s = "abc" 
Output: false
Explanation: s is not a palindrome
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input = "abc";

    int left = 0 , right = input.length() - 1; 

    bool flag = true;

    while(left<=right)
    {
        if(input[left] != input[right])
        {
            flag = false;
            break;
        }
        else
        {
            right-- , left++;
        }
    }
    
    if(flag)
        cout<<"Palindrome"<<endl;
    else
        cout<<"Not a Palindrome"<<endl;
}