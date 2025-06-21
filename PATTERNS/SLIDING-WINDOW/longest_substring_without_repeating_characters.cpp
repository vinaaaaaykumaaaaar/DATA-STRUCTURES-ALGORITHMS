#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int maxSubString(string s){
    int n = s.size();

    int maxLength = 0 , windowLength = 0;
    unordered_map<char,int> total;

    int left = 0;

    for(int right=0; right<n; ++right){

        total[s[right]]++;

        while(total[s[right]] > 1){
            if(--total[s[left]] == 0){
                total.erase(s[left]);
            }
            left++;
        }

        windowLength = right - left + 1;

        maxLength = max(maxLength , windowLength);

    }

    return maxLength;
}

int main(){
    
    string s_data = "vinaykumar";
    
    int res = maxSubString(s_data);

    cout<<"Maximum length : "<<res<<endl;
    
    return 0;
}
