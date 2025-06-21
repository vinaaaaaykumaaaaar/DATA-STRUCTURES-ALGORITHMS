#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int fruitIntoBaskets( vector<int>& fruits){

    int maxLength = 0;

    for(int i=0; i<fruits.size(); ++i){
        
        unordered_set<int> seen;

        for(int j=i; j<fruits.size(); ++j){
            
            seen.insert(fruits[j]);

            if(seen.size() > 2 ){
                break;
            }

            int windowSize = j - i + 1;
            maxLength = max(maxLength , windowSize);
        }
    }

    return maxLength;
}

int main(){

    // Example usage:
    vector<int> fruits = {3, 3, 2, 1, 2, 1, 0};

    int result =  fruitIntoBaskets(fruits);
    cout<<"Maximum fruits in the basket is "<<result<<endl;

    return 0;
}
