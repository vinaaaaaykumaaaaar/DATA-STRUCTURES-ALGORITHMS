#pragma GCC optimize("03")
#pragma GCC target ("sse4")

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;

ll a[10] = {1,2,3,4,5,6,7,8,9,10};
 
void naive_solution()
{
    // time complexity -> 
    // space complexity ->
      
}

void better_solution()
{
    // time complexity ->
    // space complexity ->

    

}

void optimal_solution()
{
    // time complexity ->
    // space complexity ->

    int i=0 , j=9;
    int k = 6;
    while(i<j)
    {
        int sum = a[i]+a[j];
        if(sum == k)
        {
            cout<<a[i]<<" "<<a[j]<<endl;
            break;
        }

        else if(sum > k) j--;
        else i++;
    }

    

}

int main()
{
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
            
   // naive_solution();
    // better_solution();
     optimal_solution();
                                      
    return 0;
}

