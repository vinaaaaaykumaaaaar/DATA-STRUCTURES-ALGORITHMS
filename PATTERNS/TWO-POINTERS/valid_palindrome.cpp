#include<iostream>
#include<string>
#include<vector>
#include<cctype>

using namespace std;


bool reverse_string(string s)
{
	int left = 0,right = s.length()-1;


	while(left<right)
	{
		while(left<right && !isalnum(s[left])) left++;
		while(left<right && !isalnum(s[right])) right--;
		
		if(tolower(s[left]) != tolower(s[right])) return false;

			left++, right--;
	}

	return true;

}

int main()
{

	string input =  "A man, a plan, a canal: Panama";

	cout<<reverse_string(input)<<endl;
	return 0;
}
