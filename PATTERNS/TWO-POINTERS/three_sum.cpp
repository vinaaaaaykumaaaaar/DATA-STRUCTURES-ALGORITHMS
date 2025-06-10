#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


vector<int> triplet(vector<int>& a , int t)
{
	sort(a.begin(),a.end());


	for(int i=0; i<a.size();i++)
	{
     		int sum = t - a[i];
		int l=i+1 , r=a.size()-1;

		while(l<r)
    		{
			if(a[l] + a[r] == sum) return {a[i] ,a[l] , a[r]};
			else if(a[l] + a[r] > sum) r--;
			else l++; 
		}
	}
	
	return {-1,-1,-1};
}



    vector<vector<int>> threeSum(vector<int>& a) {
        sort(a.begin(), a.end()); 
        int s = a.size();
        vector<vector<int>> v;
        for(int i=0 ; i<s-2;i++)
        {
            if (i > 0 && a[i] == a[i - 1]) continue;
            int l = i+1 , r = s-1;
            while(l<r)
            {
                 int  sum = a[i] + a[l] + a[r];
                if(sum == 0)
                {

                 v.push_back({a[i],a[l],a[r]});
                 l++;
                 r--;
                while (l < r && a[l] == a[l - 1]) l++;
                while(l<r && a[r] == a[r+1]) r--;

                }
                else if (sum<0)
                {
                    l++;
                }
                else {
                    r--;
                }

            }
        }
        return v;
    }

int main()
{
	vector<int> a = {-2,-1,0,1,2,3};
	int target = 13;

	vector<vector<int> >res = threeSum(a);

	for(auto x:res){
		for(auto y:x) 
     		{
     			cout<<y<<" ";
     		}
		cout<<endl;
	}
	cout<<endl;

	return 0;
}
