#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v = {1,3,5,5,6};
	int n = 5 , index = -1;

	for(int i=0; i<v.size(); i++)
	{
		if(v[i]==n)
		{
			index = i;
			break;
		}
	}

	cout<<"Index = "<<index<<endl;

	return 0;
}
