#include<iostream>
#include<vector>

using namespace std;

 int b(vector<int>& a, int l , int h,int t)
    {

        int m = (l + h) / 2;

        if(l>=h) return -1; 
        if (a[m] == t) return m;

        else if(a[m]>t) b(a , l , m-1, t);
        else b(a, m+1 , h , t);

    }

int main()
{

    vector<int> v = {1,2,3,4,5,6};

   

    cout<<b(v,0,5,-1)<<endl;
    
}