#include<iostream>
using namespace std;

int main()
{
    int n = 5;
    for(auto i=1;i<=n;i++)
    {
        for(auto j=1;j<=i;j++)
        {
            cout<<j;
        }

        cout<<endl;
    }
}