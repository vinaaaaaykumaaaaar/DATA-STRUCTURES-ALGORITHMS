#include<iostream>

using namespace std;

void recursion (int n){
	if(n<1) return ;
	else {
		cout<<"Hello World"<<endl;
		return recursion(n-1);
}
}

int main(){
	 int n = 10;
	recursion(n);
	return 0;
}
