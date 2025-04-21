#include<iostream>

using namespace std;

int main()
{
	int n ;
	cin>>n;

	int a[n+1];
	
	for(int i = 0; i < n; i++ )
		cin>>a[i];

	bool is_sorted = true;

	for(int i = 0 ; i <n ; i++)
		if(a[i] > a[i+1]) 
			is_sorted = false;

	if(is_sorted)
		cout<<"Array is sorted"<<endl;
	else
		cout<<"Array is not sorted"<<endl;

	return 0;

}
