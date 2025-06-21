#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int maxSubArray(vector<int>& arr ){

    int windowSize = 0;
    int maxSum = 0;
    unordered_map<int,int> totalElements;

    int left = 0;
    
    for(int right=0; right<arr.size(); ++right){

        totalElements[arr[right]]++;

        while(totalElements.size() > 2){
            if(--totalElements[arr[left]] == 0){
                totalElements.erase(arr[left]);
            }
            left++;
        }

        windowSize = right - left + 1;
        maxSum = max(windowSize , maxSum);
    }

    return maxSum;
}

int main(){

    vector<int> arr = {3, 3, 2, 1, 2, 1, 0};

    int res = maxSubArray(arr);

    cout<<"Maximum number of array elements : "<<res<<endl;

    return 0;
}
