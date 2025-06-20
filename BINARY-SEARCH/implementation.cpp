#include <iostream>
#include <vector>

using namespace std;

void binary_search(vector<int>& a , int t , int l , int h)
{
    int m = (l+h) / 2;

    if(a[m] == t)
    {
        cout<<"index = "<<m<<endl;
        return ;
    }

    else if (a[m] > t)
        return  binary_search(a, t, l , m-1);
    else 
        return  binary_search(a, t , m-1 , h);
}

int main()
{
    vector<int> a = {1,2,3,4,5,6,7,8,9};
    int t = 2;
    binary_search(a, t, 0 , a.size()-1);
    return 0;
}

