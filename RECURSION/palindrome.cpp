#include<iostream>

using namespace std;

string s ;
string c = "";

void palindrome (int start , int end)
{
	if( start < end)
	{
		swap(s[start] , s[end]);
		palindrome(start + 1 , end - 1);
	}
}

int main()
{
	cin>>s;
	c = s;
	palindrome(0 , s.size() - 1 );
	

	if(s == c)
		cout<<"Palindrome"<<endl;
	else 
		cout<<"Not a Palindrome"<<endl;

	return 0;

}

