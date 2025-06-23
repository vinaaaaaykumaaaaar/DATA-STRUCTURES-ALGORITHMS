#include<iostream>
#include<vector>
#include<stack>

using namespace std;


vector<int> nextGreaterElement(vector<int>& n){
    int s = n.size();
    vector<int> g (s,-1);

    stack<int> st;

    for(int i=0; i<s; i++){

        while(!st.empty() && n[i] > n[st.top()]){
            int idx = st.top();
            st.pop();
        }
        st.push(i);
    }

    return g;
}

int main(){
    vector<int> nums = {2, 1, 2, 4, 3};
    vector<int> result = nextGreaterElement(nums);

    cout << "Next Greater Elements:\n";
    for(auto x:result) cout<<x;
    cout<<endl;
    return 0;
}
