#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<char , int> count_frequency(string s)
{
    unordered_map<char , int> freq;

    for(char c : s){
    
        freq[c]++;

    }

    return freq;

}


int main(){
    
    string text = "hello world";
    auto frequency = count_frequency( text);


    for(auto x : frequency){
        cout<<"'"<<x.first<<"':"<<x.second<<endl;
    }

    char maxChar = ' ';
    int maxCount = 0;

    for(auto x: frequency){
    
        if(x.second > maxCount ){
              maxCount = x.second;
              maxChar = x.first;
        }
    }

    cout << "Most frequency : "<< maxChar << " '( " <<maxCount << " times) "<<endl;

    return 0;

}
