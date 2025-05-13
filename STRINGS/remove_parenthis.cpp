#include<iostream>
#include<string>

using namespace std;


string removeOuterParentheses(string s){

    int openCount = 0;
    int closeCount = 0;
    string result = "";
    int start = 0;


    for(int i=0; i<s.length(); i++){
    
        char c = s[i];
        if( c == '(')
            openCount++;
        else if(c == ')')
            closeCount++;

        if(openCount == closeCount)
            result += s.substr(start + 1 , i - start -1) , start = i+1;

    }

    return result;
}


int main(){
    string s1 = "(()())(())()";
    cout << removeOuterParentheses(s1) << endl;  
        
    string s2 = "()()(()())(()())";
   cout << removeOuterParentheses(s2) << endl; 

}
