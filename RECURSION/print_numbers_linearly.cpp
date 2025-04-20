#include<iostream>

using namespace std;

int count = 1;
int limit = 10;

void print_numbers_linearly()
{
	if(count > limit) return ;
	cout<<count++<<endl;
	print_numbers_linearly();
}


int main()
{
	print_numbers_linearly();
	return 0;
}
