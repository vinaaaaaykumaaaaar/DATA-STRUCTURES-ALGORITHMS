#include<iostream>
#include<set>
#include<vector>

using namespace std;

int a[5] = {1, 2, 3, 4, 5};
int b[5] = {1, 3, 5, 7, 9};

void naive_solution()
{
	// Time complexity -> O( (m+n)log(m+n) )
	// Space complexity -> O(m+n) -> m+n  is length of set s at worst case where element is unique;
	set<int> s;
	for(int i=0; i<5; i++)
		s.insert(a[i]);
	
	for(int i=0; i<5; i++)
		s.insert(b[i]);

	for(auto x:s)
		cout<<x<<" ";
	cout<<endl;

}

void optimal_solution()
{

	// time complexity -> O(n + m) -> n and m are sizes of the arrays
	// space complexity -> O(n+m) -> n and m are sizes of the arrays
	
	int i=0, j=0;
	vector<int> uni;

	while(i<5 && j<5)
	{
		if(a[i] <= b[j])
		{
			if(uni.size() ==0 || uni.back() != a[i])
				uni.push_back(a[i]);
			i++;
		}
		else
		{
			if(uni.size() ==0 || uni.back() != b[j])
				uni.push_back(b[j]);
			j++;
		}
	}

	while(i<5)
	{
		if(uni.size() == 0 || uni.back() != a[i])
			uni.push_back(a[i]);
		i++;
	}

	while(j<5)
	{
		if(uni.size() == 0 || uni.back() != b[j])
			uni.push_back(b[j]);
		j++;
	}

	for(auto x:uni)
		cout<<x<<" ";
	cout<<endl;

}

	

	

int main()
{
	// naive_solution();
	optimal_solution();
	return 0;
}
