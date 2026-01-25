#include<iostream>
using namespace std;

int main()
{
    int count = 5;

    for (auto i = 1; i <= count; i++)
    {
        for(auto j=0; j<= count-i;j++) cout<<" ";
        for(auto j = 0 ; j< i*2 -1 ; j++ ) cout<<"*";
        cout<<endl;
    }
    
    for (auto i = count; i >= 1; i--)
    {
         for(auto j=0; j<= count-i;j++) cout<<" ";
        for (auto j = 0; j < i*2 -1; j++) cout<<"*";
        cout<<endl;
        
    }
    
    
}