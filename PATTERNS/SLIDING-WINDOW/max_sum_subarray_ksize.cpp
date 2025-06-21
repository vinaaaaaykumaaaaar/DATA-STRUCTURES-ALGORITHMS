#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumSubArray(vector<int>& arr , int k){
    int maxSum = 0 , windowSum = 0;

    for(int i=0; i<k; ++i){
        windowSum += arr[i];
    }

    for(int left=0, right=k; right<arr.size(); ++left , ++right){
        windowSum -= arr[left];
        windowSum += arr[right];

        maxSum = max(maxSum , windowSum);
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
