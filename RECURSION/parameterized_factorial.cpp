#include<iostream>

using namespace std;

int fact = 1;
int number = 0;

void factorial(int number , int fact)
{
	if(number <= 1) 
	{
		cout<<"Factorial = "<<fact<<endl;
		return ;
	}
	factorial(number-1,fact * number);
}


int main()
{
	cin>>number;

	factorial(number,fact);

	return 0;
}

