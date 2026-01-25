#include<iostream>
using namespace std;

int main()
{
    int count = 5;
    for (auto i = 0; i <= count*2-1; i++)
    {
        if(i<count)
        {
            for (auto j = 0; j <= i; j++)
            {
                cout<<"*";
            }
            
        }  
        else{
            for(auto j=count; j>i-count;j--)
            {
                cout<<"*";
            }
        }    
        cout<<endl;  
    }
    
}