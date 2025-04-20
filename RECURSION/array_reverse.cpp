#include<iostream>

using namespace std;

int main()
{
	int size = 0;
	cin>>size;
	int arr[size] ;

	for(int i = 0; i < size; i++)
		cin>>arr[i];

	int j = size - 1 ;
	int i = 0;
	
	while(i<j)
	{
		swap(arr[i],arr[j]);
		i++, j--;
	}

	for(int k = 0; k < size ; k++)
		cout<<arr[k]<<" ";
	
	cout<<endl;	
	return 0;
}
