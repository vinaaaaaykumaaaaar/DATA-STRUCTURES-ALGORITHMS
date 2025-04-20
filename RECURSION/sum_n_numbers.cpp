#include<iostream>

using namespace std;

int sum = 0;

void sum_of_numbers(int number , int sum)
{
	if(number < 1) 
	{
		cout<<"Sum = "<<sum<<endl;
		return ;
	}
	sum_of_numbers(number - 1, sum + number);
}

int main()
{
	int number = 0;
	cin>>number;

	sum_of_numbers(number,sum);

	return 0;
}
	
