#include<iostream>
#include<string>


using namespace std;

string reverse(string s)
{
	int i=0;

	for(int j=0;j<=s.size(); j++)
	{
		if(s[j] == ' ' || j == s.size())
		{
			int k = j-1;
			while(i<k)
			{
				swap(s[i],s[k]);
				i++,k--;
			}

			i = j+1;
		}
	}

	return s;
}

int main()
{
	string s = "vinay kumar";

	cout<<reverse(s)<<endl;
	return 0;
}
