#include<iostream>
#include <map>
#include <string>

using namespace std;

bool anagram(string s1 , string s2){
    if(s1.size() != s2.size()) return false;

    map<char,int > m1 , m2;
    for(int i=0; i<s1.size(); i++){
        m1[s1[i]]++ , m2[s2[i]]++;

    }

    for(auto x:m1){
        if(x.second != m2[x.first]) return false;
    }

    return true;

    
}

int main(){

    string s1, s2;

    cin>>s1>>s2;

    cout<<anagram(s1, s2)<<endl;

    return 0;
}
