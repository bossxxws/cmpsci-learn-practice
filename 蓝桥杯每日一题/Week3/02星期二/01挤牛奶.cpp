//变量维护最长的区间和最长的断开区间即可
#include<bits/stdc++.h>

using namespace std;

int n;

const int N=5000+5;

typedef long long LL;

typedef pair<int,int> PII;

#define x first

#define y second

vector<PII>nums,res;

int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		nums.push_back({l,r});
	}
	
	int st=-2e9,ed=-2e9;
	sort(nums.begin(),nums.end());
	int maxs=nums[0].y-nums[0].x,mins=0;
	for(auto num :nums)
	{
		//无法合并 
		if(ed<num.x)
		{
			if(ed!=-2e9)mins=max(mins,num.x-ed);
			st=num.x;
			ed=num.y;
			res.push_back(num);
		}
		else if(ed<num.y)
		{
			ed=num.y;
			maxs=max(maxs,ed-st);
		}
	}
	maxs=max(maxs,res.back().y-res.back().x);
	cout<<maxs<<" "<<mins;
	return 0;
}
