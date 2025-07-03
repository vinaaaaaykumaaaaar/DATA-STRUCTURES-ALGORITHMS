/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


/**
Problem Statement:

    Given a valid parentheses string s, consider its primitive decomposition.
    A primitive valid parentheses string is a non-empty valid string that cannot
    be split into two or more non-empty valid parentheses strings.
    Your task is to remove the outermost parentheses of every primitive string
    in the decomposition of s and return the resulting string.

Example:

    Input: s = "(()())(())"
    Primitive Decomposition: (()()) + (())
    Remove Outermost Parentheses: ()() + ()
    Output: ()()()

 */



 /*

Approaches:


Brute Force (Conceptual): 
    A conceptual approach would involve identifying all primitive strings, 
    removing their outer parentheses, and concatenating the results. However
    , this is complex and inefficient due to the difficulty in accurately 
    identifying primitive string boundaries.

Better Approach (Using a Stack):
    A stack can be used to track parentheses nesting. When iterating through
    the string, push '(' onto the stack and append it to the result if the stack
    is not empty. For ')', pop from the stack and append it to the result if
    the stack is not empty.

Optimal Approach (Using a Counter): 
    The most efficient approach uses a counter to track nesting depth.
 
 */


 #include<iostream>
 #include<stack>
 #include<string>
 

 using namespace std;


std::string removeOuterParentheses(std::string s) {
        std::string ans = ""; // String to store the result
        int depth = 0; // Counter to track the nesting depth

        for(auto c : s){
            if(c == '('){
                if(depth > 0){
                    ans += c;
                }
                depth++;
            }else if(c == ')'){
                depth--;
                if(depth>0){
                    ans += c;
                }
            }
        }

        return ans;
}


int main()
{
    std::string s = "(()())(())";
    cout<<removeOuterParentheses(s)<<endl;

    return 0;
    
}




    

