#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr = { 10,2,4,9,3,13,1};

    int key = 100; 

    int position = -1;

    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] == key)
        {
            position = i+1; 
            break;
        }
    }

    if(position > -1)
    {
        cout<<"Element "<<key<<" found at the position "<<position<<endl;
    }
    else 
    {
        cout<<"Element not found in the array"<<endl;
    }

    return 0;
}