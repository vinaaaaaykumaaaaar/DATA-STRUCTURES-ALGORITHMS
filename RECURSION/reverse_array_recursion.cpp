#include<iostream>

using namespace std;

void reverse(int arr[],int start,int end)
{
	if(start < end)
	{
		swap(arr[start] , arr[end]);
		reverse(arr,start + 1, end - 1);
	}
}

int main()
{
	int n = 5 ;
	int arr[] = {5,4,3,2,1};

	reverse(arr,0,n-1);

	for(int i = 0; i < n; i++)
		cout<<arr[i]<<endl;

	return 0;
}
