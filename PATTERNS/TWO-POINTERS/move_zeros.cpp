#include<iostream>
#include<vector>

using namespace std;

vector<int> move_zeros(vector<int>& v)
{

	int z = 0;
	for(int i=0; i<v.size();i++)
		if(v[i] != 0) swap(v[i],v[z]), z++;

	return v;
}

int main()
{
	vector<int> v = {0, 1, 0, 3, 12};

	vector<int> res = move_zeros(v);
	for(auto x:res) cout<<x<<" ";
	cout<<endl;

	return 0;
}
