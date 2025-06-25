#include<iostream>
using namespace std;

void recursion(int n){
	if(n>10) return ;
	else {
	cout<<n<<endl;
	recursion(n+1);
	}
}

int main(){
	int n = 10;
	recursion(1);
	return 0;
}
