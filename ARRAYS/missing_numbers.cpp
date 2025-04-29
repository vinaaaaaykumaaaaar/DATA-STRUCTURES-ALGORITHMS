#include<iostream>
#include<map>

using namespace std;

int a[4] = { 1,2,3, 4}; 

void naive_solution()
{
	// time complexity -> O(n)
	// space complexity -> O(1)
	for(int i=0; i<5; i++)
		if(a[i] != i+1)
		{
			cout<<i+1<<endl;
			break;
		}

}

void better_solution()
{
	int sum = 0;
	for(int i=0 ; i<4; i++)
		sum = sum + a[i];
	
	int total_sum = (5*6)/2;
	cout<<total_sum - sum <<endl;

}
	

int main()
{
	// naive_solution();
	better_solution();
	return 0;
}
