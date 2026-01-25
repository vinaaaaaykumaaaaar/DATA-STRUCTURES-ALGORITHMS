#include<iostream>
using namespace std;

int main()
{
    int count = 5;
    for (int i = 1; i <= count; i++)
    {
        for (auto j = 1; j <= i; j++)
        {
            cout<<((i+j)%2==0);
        }
        cout<<"\n";
        
    }
    
    
}