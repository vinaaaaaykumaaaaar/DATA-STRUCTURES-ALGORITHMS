#include<iostream>

using namespace std;

int sum_of_numbers(int number)
{
	if(number == 0) return 0;
	return	number + sum_of_numbers(number - 1);
}


int main()
{
	int number = 0;
	cin>>number;
	
	cout<<"Sum = "<<sum_of_numbers(number)<<endl;
	return 0;
}

