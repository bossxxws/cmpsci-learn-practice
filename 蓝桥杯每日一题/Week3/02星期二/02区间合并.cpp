#include<bits/stdc++.h>

using namespace std;

#define x first

#define y second

typedef pair<int,int> PII;

int n;

vector<PII> a,res;

int main()
{
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		
		PII t={l,r};
		 
		a.push_back(t);
	}
	
	int st=-2e9,ed=-2e9;
	sort(a.begin(),a.end());
	for(auto num:a)
	{
		//无法合并 
		if(num.x>ed)
		{
			ed=num.y;
			res.push_back(num);
		}
		else if(ed<num.y)
		{
			ed=num.y;
		}
	}
	cout<<res.size();
	return 0;
} 
