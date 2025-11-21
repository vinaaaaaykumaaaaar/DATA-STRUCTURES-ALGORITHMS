#include<bits/stdc++.h>
using namespace std;

int main()
{
	string password = "Vinay@12345";
	string inputPassword = "" ;

	struct User
	{
		string name = "Vinay Kumar";
		int balance = 5000000;
		int lastCredit = 1000; 
		int lastDebit = 30000; 
	} ;
	
	User user;

	cout<<"Please enter your password :"<<endl	
	
	for(int i=0; i<3; i++)	
	{
		cin>>inputPassword; 
		if ( inputPassword == password)
		{
			break ; 
		}
		else
		{	cout<<"Wrong Password : Please enter the password again "<<endl;
			inputPassword = "";
		}
	}

	if(inputPassword.size())
	{
		cout<<"User Name : " <<user.name<<endl;
		cout<<"Balance : "<<user.balance<<endl;
		cout<<"Last Credit Balance : "<<user.lastCredit<<endl;
		cout<<"Last Debit Balance : "<<user.lastDebit<<endl;
	}
	else
	{
		cout<<"Invalid Password : Maximum 3 attempt over , please try later "<<endl;
	}

	return 0;
}
