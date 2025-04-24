#include<iostream>

using namespace std;

int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };


void reverse(int start , int end)
{
	while(start < end)
	{
		swap(a[start], a[end]);
		start++ , end--;
	}

}

void naive_solution()
{
	// Time complexity -> O(n);
	// Space complexity -> O(n);
	
	int b[10];

	for(int i = 0; i < 10; i++)
	{
		b[i] = a[i+1];
	}

	b[9] = a[0];

	for(int i = 0; i < 10; i++)
		cout<<b[i]<<endl;
}

void optimal_solution()
{
	// Time complexity -> O(n);
	// space complexity -> O(1);
	
	reverse(0,9);
	reverse(0,8);

	for(int i = 0; i < 10; i++)
		cout<<a[i]<<endl;
}

void optimal_solution_2()
{
	// Time complexity -> O(n);
	// Space complexity ->O(1);
	
	int b = a[0];

	for(int i = 0; i < 10 ; i++)
	{
		if( i == 9)
			a[i] = b;
		else 
			a[i] = a[i+1];
	}

	for(int i = 0; i < 10 ; i++)
		cout<<a[i]<<endl;
}

int main()
{
	// naive_solution();
	// optimal_solution();
	optimal_solution_2();

	return 0;
}

