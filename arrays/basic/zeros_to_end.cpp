#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    vector<int> temp(arr.size(),0);
    
    // Brute force algorithm : TC -> O(N) , SC -> O(N) 
    int j=0;
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] != 0)
        {
            temp[j] = arr[i];
            j++;
        }
    }

    // Two Pointers approach : TC -> O(N) , SC -> O(1)
    int non_zero = 0 , zero = 0;

    while(non_zero<arr.size())
    {
        if(arr[non_zero] != 0 )
        {
            swap(arr[non_zero] , arr[zero]);
            non_zero++ , zero++;
        }
        else
        {
            non_zero++;
        }
    }


    for(auto ele : arr) cout<<ele<<" ";
    cout<<"\n";

    return 0;
}