#include<iostream>
#include<vector>

using namespace std;

int lower_bound(vector<int> a , int t , int ans , int l , int h)
{
    if(l > h) return ans;

    int m = (l+h) / 2;
    if(a[m] >= t)
    {
        ans = m;
        return lower_bound(a, t, ans , l , m-1);
    }else {
        return lower_bound(a, t, ans , m+1 , h);
    }

}

int main()
{
    vector<int > v = {3, 5, 8, 15, 19};
    int target = 90;

   int res =  lower_bound(v, target , v.size() , 0 , v.size()-1);
    res == v.size() ? cout<<"NO lower bound"<<endl  : cout<<res<<endl;

    return 0;
}
