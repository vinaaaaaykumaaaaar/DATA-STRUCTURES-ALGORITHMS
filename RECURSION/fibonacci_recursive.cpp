#include<iostream>
#include<chrono>

using namespace std;

int fibonacci(int n)
{
	if(n==0) return 0;
	else if(n == 1) return 1;
	else return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
	int n;
	cin>>n;

	auto start = chrono::high_resolution_clock::now();
	cout<<fibonacci(n)<<endl;
	auto end = chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	cout<<static_cast<double>(duration) / 1000000000.0;

	return 0;
}

