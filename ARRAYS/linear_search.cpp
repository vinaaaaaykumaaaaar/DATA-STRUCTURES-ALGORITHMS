#include<iostream>

using namespace std;

int a[5]={ 1, 2, 3, 4, 5 };

int linear_search(int key)
{
	for(int i=0; i<5; i++)
		if(a[i] == key) return i;

	return -1;
}


int main()
{
	int res = linear_search(4);
	if(res == -1 )
		cout<<"Element not found"<<endl;
	else 
		cout<<"Element found at "<<res<<" index"<<endl;

	return 0;
}
