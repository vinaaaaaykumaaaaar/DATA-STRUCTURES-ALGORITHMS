#include <iostream>

using namespace std;

void swap(int64_t number1, int64_t number2)
{
	int64_t temp_variable;

	cout<<"----------- Before swapping -------------\n";
	cout<<"Number1 = "<<number1<<" "<<"Number2 = "<<number2<<endl;

	temp_variable = number1;
	number1 = number2;
	number2 = temp_variable;

	cout<<"----------- After swapping --------------\n";
	cout<<"Number1 = "<<number1<<" "<<"Number2 = "<<number2<<endl;
}


int main()
{
	cout<<"Enter the two numbers\n";
	int64_t number1, number2;

	cin>>number1>>number2;
	
	swap(number1, number2);
	return 0;
}
