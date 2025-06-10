#include<iostream>
#include<vector>

using namespace std;

vector<int> merge(vector<int>& a , vector<int>& b)
{
	int i = 0 , j=0;
	vector<int> res;

	while(i<a.size() && j<b.size())
	{
		if(a[i] < b[j]) i++;
		else if (b[j] < a[i]) j++;
		else 
		{
			if(!res.empty() && a[i] == res.back()) 
			{
				i++;
				j++;
			}
			else
			{
				res.push_back(a[i]);
				i++,j++;
			}
		}
			
	}

	return res;
}


int main()
{
	vector<int> a ={1,2,3,3,4,5,6,7} ;
	vector<int> b = {3,3,4,4,5,8};


	vector<int> res = merge(a,b);

	for(auto x:res) cout<<x<<" ";
	cout<<endl;

	return 0;
}
