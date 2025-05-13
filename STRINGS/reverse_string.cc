#include<iostream>
#include<string>
#include<stack>

using namespace std;

string reverseString(string s){
    stack<string> st;

    string temp = "";
    for(int i=0; i<=s.length(); i++){
        
        if(s[i] == ' ' || i == s.length())
            st.push(temp) , temp = "";
        else
            temp += s[i];
    }

    string result = "";
    while(st.size() != 1){
    
        result += st.top() + " ";
        st.pop();
    }

    result += st.top() ;


    return result;

}


int main(){
    string name = "I name is Vinay Kumar";
    cout<<reverseString(name)<<endl;

}
