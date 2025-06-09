#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    vector<int> v = {1,2,1,2,3,4,5,5,5,5};

    map<int , int > m;

    for(int i=0; i<v.size(); i++){
        m[v[i]]++;
    }

    for (auto x:m){
        if(x.second > 1){
            cout<<x.first<<" repeats "<<x.second<<" times "<<endl;
        }
    }

    return 0;
}
