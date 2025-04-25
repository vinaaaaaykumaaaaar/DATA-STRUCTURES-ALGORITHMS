#include<iostream>
using namespace std;

int a[8] = {1 ,0 ,2 ,3 ,0 ,4 ,0 ,1};

void naive_solution()
{
	// Time complexity -> O(n)
	// Space complexity -> O(n)
	
	int b[8]  = {0};
	int j = 0;

	for(int i=0; i<8; i++)
		if(a[i] != 0)
			b[j] = a[i], j++;


	cout<<"Naive Solution"<<endl;
	for(int i=0; i<8; i++)
		cout<<b[i]<<" ";
	cout<<endl;	
}

void optimal_solution()
{
	int j = -1;
	for(int i=0; i<8; i++)
		if(!a[i]) 
		{
			j = i;
			break;
		}

	for(int i= j+1; i<8; i++)
		if(a[i])
			swap(a[i] , a[j]) , j++;

	cout<<"Optimal Solution"<<endl;
	for(int i=0; i<8; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
			


int main()
{
	cout<<"Original Array"<<endl;
	for(int i=0; i<8; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	cout<<"---------------------"<<endl;

	// naive_solution();
	optimal_solution();
	return 0;
}
