#include<iostream>
#include<vector>

using namespace std;

int remove_duplicates(vector<int>& n )
{
	if(n.empty()) return 0;

	int i=0;
	for(int j=1; j<n.size(); j++)
		if(n[i] != n[j]) i++ , n[i] = n[j];

	return i;
	
}


int main()
{
	vector<int> n = {1, 1, 2, 2, 2, 3, 4, 4};


	cout<<"Original array"<<endl;
	for(auto x:n) cout<<x<<" ";
	cout<<endl;


	int res = remove_duplicates(n);
	cout<<"After removing duplicates"<<endl;
	for(int i=0; i<= res; i++) cout<<n[i]<<" ";
	cout<<endl;

	return 0;
}
