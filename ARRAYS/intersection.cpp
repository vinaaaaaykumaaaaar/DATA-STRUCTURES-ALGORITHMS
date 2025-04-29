#include<iostream>
#include<vector>
#include<set>
#include<map>

using namespace std;

int a[5] = {1, 2, 3, 4, 5};
int b[5] = {1, 3, 5, 7, 9};

void naive_solution()
{
	// time complexity -> O(n^2)
	// space complexity -> O(n+m) -> n and m are sizes of the given arrays 
	set<int> s;
	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
			if(a[i] == b[j])
				s.insert(a[i]);

	for(auto x:s) 
		cout<<x<<" ";
	cout<<endl;

}

void optimal_solution()
{
	int i=0 , j=0;
	vector<int> inter;
	while(i<5 && j<5)
	{
		if(a[i] == b[j])
		{
			if(inter.empty() || inter.back() !=a[i])
				inter.push_back(a[i]);

		i++ , j++;
		}

		if(a[i] < b[j])
			i++;

		if(a[i] > b[j])
			j++;

	}

	for(auto x:inter) 
		cout<<x<<" ";
	cout<<endl;
}



int main()
{
	// naive_solution();
	optimal_solution();
	return 0;
}
