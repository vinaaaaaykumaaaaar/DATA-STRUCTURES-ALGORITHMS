#include<iostream>
#include <string>
#include <stack>

using namespace std;


string decode(const string& s){

    stack <int> countStack;
    stack <string> stringStack;

    int currentNum = 0;
    string currentStr;

    for (char c:s){
        if(isdigit(c)){
                currentNum = currentNum * 10 + (c - '0');
        }

        else if (c == '['){
        countStack.push(currentNum);
        stringStack.push(currentStr);

        currentNum = 0;
        currentStr.clear();
        }

        else if (c == ']'){
        int repeatCount = countStack.top();
        countStack.pop();

        string lastStr = stringStack.top();
        stringStack.pop();

        string expanded;
        expanded.reserve(currentStr.size() * repeatCount);
        for(int i =0 ; i<repeatCount; i++){
        expanded += currentStr;
        }

        currentStr = lastStr + expanded;
        }
        else{
        currentStr.push_back(c);
        }
    }

    return currentStr;
}

int main(){
    string s = "3[a2[c]]";
    cout<<decode(s)<<endl;
    return 0;
}
