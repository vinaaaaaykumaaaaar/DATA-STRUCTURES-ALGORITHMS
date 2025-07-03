#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

bool isBalanced(const string& s){
    stack<char> p;

    for(int i=0; i<s.size(); ++i){
        if(s[i] == '{' || s[i] == '(' || s[i] == '['){
            p.push(s[i]);
        }

        else if(!p.empty() && 
            ((p.top() == '(' && s[i] == ')') ||
             (p.top() == '{' && s[i] == '}') ||
             (p.top() == '[' && s[i] == ']'))
            ){
        p.pop();
        }else {
        return false;
        }
    }

    return p.empty();
}

int main(){
    string s = "[{([])}";

    if(isBalanced(s)){
        cout<<"Parenthesis are balanced"<<endl;
    }else{
        cout<<"Not a valid parenthesis"<<endl;
    }

    return 0;
}
