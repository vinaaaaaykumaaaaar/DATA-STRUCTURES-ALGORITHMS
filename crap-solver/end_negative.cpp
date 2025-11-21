#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v;
	int input ;  
	while(true)
	{
		cin>>input;
		if(input < 0)
		{
			break;
		}
		v.push_back(input);
	}

	for(auto x : v) cout<<x<<" ";
	cout<<endl;

	return 0;
	
}
