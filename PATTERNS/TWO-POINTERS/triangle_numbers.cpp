#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> solve(vector<int>& a)
{

     vector<vector<int>> b;
	for(int i=0; i<a.size(); i++){
		
		int j = i+1 , k = a.size()-1;

		while(j < i ){
			if((a[i] + a[j]) > a[k] && (a[j] + a[k]) > a[i] && (a[k] + a[i] ) > a[j]){
     				b.push_back({a[i] , a[j] , a[k]});
			}

			i++ , j--;
	}
	}

		return b;

}

int main()
{
	vector<int> v = {11,4,9,6,15,18};

	vector<vector<int>> t = solve(v);
	cout<<t.size()<<endl;
	cout<<endl;

	return 0;
}
