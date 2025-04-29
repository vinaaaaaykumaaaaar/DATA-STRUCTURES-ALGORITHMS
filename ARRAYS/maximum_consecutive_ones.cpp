#include<iostream>

using namespace std;

int a[9] = {1, 1, 0, 1, 1, 1, 1, 1, 1};

void optimal_solution()
{
	int count =0 , max = 0;

	for(int i=0; i<9; i++)
		if(a[i])
			count++;

		else if(!a[i])
		{
			if(max < count ) max = count ;
			count = 0;
		}
			
	if(max < count ) max = count ;
	cout<<max<<endl;
}
	

int main()
{
	optimal_solution();	
	return 0;
}
