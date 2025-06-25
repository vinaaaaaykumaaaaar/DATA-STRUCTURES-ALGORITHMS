#include<iostream>
using namespace std;

int recur(int n){
	if(n<1) return 0;
	else return n + recur(n-1);
}

int main(){

	int n = 10;
	cout<<recur(n)<<endl;
	return 0;
}
