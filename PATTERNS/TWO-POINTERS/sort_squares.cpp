#include<iostream>
#include<vector>

using namespace std;

int square(int n)
{
	return n*n;
}

vector<int> squares(vector<int> a)
{
	int i = 0;
	vector<int> res;
	while(i<a.size() && a[i] < 0)
		i++;

        int j = i-1;

	while(j>=0 && i<a.size())
	{
		if(square(a[i]) < square(a[j]))
		{
			res.push_back(square(a[i]));
			i++;
		}
		else if(square(a[j]) < square(a[i]))
		{
			res.push_back(square(a[j]));
			j--;
		}
		else
		{
			res.push_back(square(a[i]));
			res.push_back(square(a[j]));
			i++;
			j--;
		}
	}


        while(i<a.size())
	{
		res.push_back(square(a[i]));
		i++;
	}


	while(j>=0)
	{
		res.push_back(square(a[j]));
		j--;
	}
	
	return res;
}

int main()
{
	vector<int> a = {-7,-3,2,3,11};
	
	vector<int> res = squares(a);

	for(auto x:res) cout<<x<<" ";
	cout<<endl;

	return 0;
}
