#include<iostream>

using namespace std;

int main()
{
    int n=5;

    for (auto i = 1; i <= n; i++)
    {
        for(auto j=0; j<n-i;j++)
        {
            cout<<" ";
        }
        /* code */
        for (auto j = 0; j < i*2 -1; j++)
        {
            cout<<"*";
        }

        cout<<endl;
        
    }
    
}