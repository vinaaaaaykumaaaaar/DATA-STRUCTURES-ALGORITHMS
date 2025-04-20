#include<iostream>

using namespace std;

int count = 0;

void recursion()
{
	if(count == 5)
	{
		cout<<count<<endl;
		return ;
	}
	count++;
	recursion();
}

int main()
{
	recursion();
	
	return 0;
}

	
