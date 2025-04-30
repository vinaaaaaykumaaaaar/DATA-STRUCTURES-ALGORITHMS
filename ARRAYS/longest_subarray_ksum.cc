#include<iostream>

using namespace std;

int a[10] = {1,2,3,1,1,1,1,4,2,3};
int key = 4;

void naive_solution()
{
	int len=0;
	for(int i=0; i<10; i++)
	{
		int s=0;
		for(int j=0; j<10; j++)
		{
			s += a[j];
			if(key == s)
				if(len < j-i+1)
				{
					len = j-i+1;
					cout<<len<<endl;
				}
		}
	}
	cout<<len<<endl;
}


int main()
{
	naive_solution();
	return 0;
}
