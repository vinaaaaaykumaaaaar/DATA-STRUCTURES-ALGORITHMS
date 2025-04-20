#include<iostream>

using namespace std;

int limit = 1;
int count = 10;

void print_numbers_reversly()
{
	if(count < limit) return ;
	cout<<count--<<endl;
	print_numbers_reversly();
}

int main()
{
	print_numbers_reversly();

	return 0;
}
