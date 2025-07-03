#include<iostream>
#include<string>
using namespace std;

int main()
{
    string name = "vinay";
    string name1 = "sdf";

    string name2 = name+name;
    if(name2.find(name1) != std::string::npos){
        cout<<"yes"<<endl;
    }else {
        cout<<"no"<<endl;
    }
}