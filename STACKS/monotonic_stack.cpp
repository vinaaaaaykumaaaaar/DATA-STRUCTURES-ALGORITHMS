#include <iostream>
#include <vector>
#include <stack>

using namespace std;



 vector<int> nextGreaterElement(const vector<int>& nums){
     int n = nums.size();
     vector<int> result (n,-1);

     stack<int> stk;

     for(int i=0; i<n; ++i){
         while(!stk.empty() && nums[i] > nums[stk.top()]){
             int idx = stk.top();
             stk.pop();
             result[idx] = nums[i];
         }
         stk.push(i);
     }
    return result;

 }

int main(){
    vector<int> nums = {2, 1, 2, 4, 3};
    vector<int> result = nextGreaterElement(nums);

    cout << "Next Greater Elements:\n";
        for (int i = 0; i < nums.size(); ++i) {
                    cout << nums[i] << " --> " << result[i] << endl;
                        }
        

    return 0;
}
