#include<iostream>
#include<set>

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

int main()
{
	naive_solution();
	return 0;
}
