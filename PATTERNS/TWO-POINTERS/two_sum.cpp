#include<iostream>
#include<vector>

using namespace std;

vector<int> two_sum(vector<int>& num, int target)
{

	int left = 0;
	int right = num.size()-1;


	while(left < right )
	{
		int cur_sum = num[left] + num[right];

		if(cur_sum == target )
		{
			return { num[left] , num[right] };
		}

		if(cur_sum > target)
			right--;
		else 
			left++;
	}

	return { -1 , -1};
}


int main()
{
	vector<int> arr = {2, 7, 11, 15};
	int target = 9;

	vector<int > result = two_sum(arr,target);


	for(auto x:result)
		cout<<x<<" ";
	cout<<endl;

	return 0;
}

