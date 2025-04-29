#include<iostream>
#include<map>

using namespace std;

int a[7] = {1,1,2,3,3,4,4,};

void naive_solution()
{
	map<int,int> m;
	for(int i=0; i<7;i++)
		m[a[i]]++;

	for(auto x:m)
	{
		if(x.second == 1)
			cout<<x.first<<endl;
		
		if(x.second == 2)
			cout<<"number that appeared twice "<<x.first<<endl;
	}
	cout<<endl;


}


int main()
{
	naive_solution();
	return 0;

}
