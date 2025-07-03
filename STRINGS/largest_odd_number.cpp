/*
Largest Odd Number in String - LeetCode Problem


Problem Statement:


    You are given a string num representing a large integer. 
    Your task is to find the largest-valued odd integer that 
    is a non-empty substring of num, or an empty string "" 
    if no odd integer exists. 

Key Concepts:
    Substring: A continuous sequence of characters within a string.
    Odd Integer: An integer that is not divisible by 2. Oddness is
                 determined by the last digit of the number.
    Largest-valued: The goal is to find the substring representing 
                    the largest odd integer. 

Example Cases:

Input: num = "52"
Output: "5"
Explanation: The substrings are "5", "2", and "52". "5" is the only odd number.

Input: num = "4206"
Output: ""
Explanation: No odd number can be formed from the substrings of "4206".

Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number. 
*/

#include<iostream>
#include<string>


using namespace std;

std::string largestOddNumber(std::string num){
    string res = "";

    for(int i=num.length()-1; i>=0; --i){
        if((num[i]-'0')% 2 != 0){
            for(int j=0; j<=i;j++){
                res += num[j];
            }
            return res;
        }
    }

    return "";
}

int main()
{

    cout<<largestOddNumber("52")<<endl;
    cout<<largestOddNumber("4206")<<endl;
    cout<<largestOddNumber("35427")<<endl;
}