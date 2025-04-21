#include<iostream>

using namespace std;

int main()
{
	int n ; 
	cin>>n;
	int a[n+1];

	for(int i = 0; i<n; i++)
		cin>>a[i];

	int largest = a[0], second_largest = -25;

	for(int i = 1; i<n; i++)
	{
		if(a[i] > largest) 
		{
			second_largest = largest;
			largest = a[i];
		}
		else if( a[i] < largest && a[i] > second_largest)
		{
			second_largest = a[i];
		}
	}

	cout<<"Largest = " <<largest<<endl;
	cout<<"Second Largest = " <<second_largest<<endl;

	return 0;
}
