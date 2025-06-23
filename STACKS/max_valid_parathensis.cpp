#include <iostream>
#include <stack>
#include <string>


using namespace std;

int valid(const string& s){
    int maxLen = 0;
    stack<int> st;

    for (int i=0; i<s.size(); i++){
        if (s[i] == '('){
            st.push(i);
        }
        else{
            st.pop();

            if(st.empty()){
                st.push(i);
            }else{
                maxLen = max(maxLen, i - st.top());
            }

        }
    }

    return maxLen;
}

int main(){
    string s = "())))";
    cout<<valid(s)<<endl;
    return 0;
}
