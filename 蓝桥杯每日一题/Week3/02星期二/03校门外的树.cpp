#include<bits/stdc++.h>

using namespace std;

int l,n;

#define x first

#define y second

const int L=1e4+5;

typedef long long LL;

typedef pair<int,int> PII;

int st=-2e9,ed=-2e9;

vector<PII>nums,res;

int main()
{
	cin>>l>>n;
	
	for(int i=1;i<=n;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		
		nums.push_back({l,r});
		
	}
	
	sort(nums.begin(),nums.end());
	int sum=0;
	for(auto num:nums)
	{
		if(num.x>ed)
		{
		    if(ed!=-2e9)sum+=ed-st+1;//�˵��Ҳ����
			ed=num.y;
			st=num.x;
			res.push_back(num);
		}
		else if(ed<num.y)
		{
			ed=num.y;
		}
	}
	
	sum+=ed-st+1;//�˵��Ҳ����
	
	cout<<l+1-sum;//������l+1����
	return 0;
} 
