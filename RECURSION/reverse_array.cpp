#include<iostream>
#include<vector>

using namespace std;

vector<int> recursion(vector<int>& a , int l , int r){

	if( l >= r) return a;
	else {
	swap(a[l] , a[r]);
	return recursion(a, l+1 , r-1);
	}

}

int main(){
	vector<int> a = {1,2,3,4,5};
	int n = a.size()-1;

	vector<int> v = recursion(a , 0 , n );
	for(auto x: v) cout<<x;
	cout<<endl;
 	return 0;
}  
