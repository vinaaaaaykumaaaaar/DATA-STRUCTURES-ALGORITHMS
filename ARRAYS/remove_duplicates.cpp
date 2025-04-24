#include<iostream>
#include<set>

using namespace std;

int a[10] = { 1 , 2 , 2 , 3 , 3, 3 , 4, 4 , 4, 4 } ;

void naive_solution()
{
	// Time Complexity Analysis
	// for( 1 -> n[size of array] ) -> O(n-1)
	// space complexity -> O(k) where k is number of unique elements

	int b[10] ;
	b[0] = a[0];
	int j = 1;

	for(int i = 1 ; i < 10 ; i++ )
	{
		if( a[i] != a[i-1] )
		{
			b[j] = a[i] ;
			j++;
		}
	}

	for(int i = 0 ; i < j ; i++ )
		cout<<b[i]<<endl;

}

void using_set_dataStructure()
{
	// Time Complexity Analysis
	// O(nlogn) -> inserting into an set
	// space complexity -> O(n)
	
	set<int> s;
	for(int i = 0; i < 10; i++)
		s.insert(a[i]);

	for(auto x:s)
		cout<<x<<endl;
}

// Optimal solution

void optimal_solution()
{
	// Time Complexity Analysis 
	// TC -> O(n) -> single traversal using for loop
	// SC -> O(1) -> extra i variable
	
	int i = 0;
	for(int j = 1; j < 10 ; j++)
	{
		if(a[i] != a[j])
		{
			i++;
			a[i] = a[j];
		}
	}

	for(int j = 0 ; j <= i ; j++)
		cout<<a[j]<<endl;

}

int main()
{
	// naive_solution();
	// using_set_dataStructure();
	optimal_solution();

	return 0;
}
