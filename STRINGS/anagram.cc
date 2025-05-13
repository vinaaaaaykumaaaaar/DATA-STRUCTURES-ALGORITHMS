#include<iostream>
#include<string>
#include<map>


using namespace std;


// wrong implementation


bool anagram(string s1, string s2){
    map<char,int> m1 = {};
    map<char, int> m2 = {};

    if(s1.length() != s2.length())
        return false;

    for(int i=0;i<s1.length(); i++){
        m1[s1[i]]++;
    }

    for(int i=0; i<s2.length(); i++){
        m2[s2[i]]++;
    }

    for(int i=0; i<s1.length(); i++){
        if(m1[s1[i]] != m2[s2[i]])
            return false;

    }
    return true;

 
}


int main(){
    string s1= "RULES" , s2 = "LESRT";
    
    if(anagram(s1, s2))
        cout<<"anagram"<<endl;
    else 
        cout<<"not an anagram"<<endl;
}

