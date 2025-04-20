#include<iostream>

using namespace std;

int count = 0;

void print_name()
{
	if(count == 5) return ;
	cout<<"Vinay Kumar"<<endl;
	count++;
	print_name();
}

int main()
{
	print_name();
	return 0;
}
