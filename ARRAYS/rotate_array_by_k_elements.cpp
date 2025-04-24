#include<iostream>

using namespace std;

int a[7] = { 1, 2, 3, 4, 5, 6, 7 };

void naive_solution(int k_elements)
{
	// Time complexity -> O(n)
	// Space complexity -> O(k)
	int b[k_elements] = {0};
	int k = k_elements;

	for(int i = 0;  i<k; i++)
		b[i] = a[i];

	int j = k;

	for(int i=0; i<7-k; i++)
		a[i] = a[j] , j++;

	j =0;
	for(int i=7-k;i<7;i++)
		a[i] = b[j], j++;

	for(int i=0; i<7; i++)
		cout<<a[i]<<" ";
	cout<<endl;	

}

void reverse(int start, int end)
{
	while(start < end)
		swap(a[start] , a[end]) , start++, end--;
}

void optimal_solution(int k)
{

	cout<<"Orignial array"<<endl;
	cout<<"--------------------"<<endl;
	for(int i=0; i<7; i++) cout<<a[i]<<" ";
	cout<<endl;
	cout<<"--------------------"<<endl;

	reverse(0,6);
	reverse(0,k-1);
	reverse(k,6);
	
	cout<<"Rotated Array"<<endl;
	cout<<"--------------------"<<endl;
	for(int i=0;i<7;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	cout<<"--------------------"<<endl;
}

int main()
{
	//naive_solution(2);
	optimal_solution(4);
	return 0;
}

