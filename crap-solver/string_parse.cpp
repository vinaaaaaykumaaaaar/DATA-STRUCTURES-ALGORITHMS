#include<bits/stdc++.h>
using namespace std;

int main()
{
	string phrase = "Vinay Kumar|vinaykumar@gmail.com|7892394250|Bengaluru";
	string username = "";
	
	for(int i=0 ; i<phrase.size() ; i++)
	{
		if( phrase[i] == '|' )
		{
			break; 
		}
		username += phrase[i];
	}
	cout<<"User name is "<<username <<endl;
	
	return 0;
}
