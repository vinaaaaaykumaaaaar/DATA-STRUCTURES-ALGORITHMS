#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(){

    unordered_map<string , int> g;

    g["vini"]=90;
    g["vinu"]=100;

    string name = "vin";
    
    cout<< g.find(name) == g.end()<<endl;

    return 0;
}
