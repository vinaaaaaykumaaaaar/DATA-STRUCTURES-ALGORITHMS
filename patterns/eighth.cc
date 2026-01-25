#include<iostream>
using namespace std;

int main()
{
    int count=5;

    for (auto i = count; i >=1; i--)
    {
        for (auto j = i; j < count; j++)
        {
            cout<<" ";
        }
        
        for (auto j = 0; j < i*2 -1; j++)
        {
          cout<<"*";
        }

        cout<<endl;
        
    }
    
}