#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int solve(vector<int>& v)
{
	int m = -1;
	int i = 0 , j = v.size() -1 ;
	while(i<j)
	{
		int temp = min(v[i],v[j]) * (j-i);
		m = max(m, temp);
		
		v[i] > v[j] ? j-- : i++;
	}
	return m;
}
int main()
{
	vector<int> v = {1,2,1};

	cout<<solve(v)<<endl;

	return 0;
}

