#include<iostream>
#include<vector>
#include<algorithm>

const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

using namespace std;

static inline int max_container(vector<int>& a)
{

	int left = 0 , right = a.size() - 1;

	int res = -1;

	while(left < right)
	{
		int curr = min(a[left] , a[right]) * (right - left);
		res = max(res , curr);
		
		if(a[left] < a[right]) left++;
		else right--;
	}

	return res;

}


int main()
{

	vector<int> a = {2, 1, 8, 6, 4, 6, 5, 5};

	cout<< max_container(a)<<endl;

	return 0;
}
