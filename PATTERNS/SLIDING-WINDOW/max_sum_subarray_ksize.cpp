#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumSubArray(vector<int>& arr , int k){

    int maxSum = 0, windowSum = 0 ;

    // creating a initial window 
    for(int i=0; i<k; ++i){
        windowSum += arr[i];
    }

    maxSum = windowSum;

    for(int left=0 , right=k; right<arr.size(); ++left , ++right){
        windowSum -= arr[left];
        windowSum += arr[right];
        maxSum = max(windowSum , maxSum);
    }

    return maxSum;

}

int main(){

    //example data:
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;

    int result = maximumSubArray(arr,k);

    cout<<"Maximum sum of subarray of size "<<k<<" : "<<result<<endl;

    return 0;
}
