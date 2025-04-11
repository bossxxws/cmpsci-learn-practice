#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N=5e5+5; 

int n,a,b;

unordered_set<int>v;

unordered_map<int,int>mapv;
unordered_map<int,int>mapu;

int main()
{
	cin>>n>>a>>b;
	
	for(int i=1;i<=a;i++)
	{
		//输入v :index value
		int x,y;
		scanf("%d%d",&x,&y);
		v.insert(x);
		mapv[x]=y;
	}
	LL sum=0;
	for(int i=1;i<=b;i++)
	{
		//输入u :idx value
		int x,y;
		scanf("%d%d",&x,&y);
		if(v.find(x)!=v.end())//v里面也存在 
		{
			sum+=(LL)y*mapv[x];
		}
	}
	
	cout<<sum;
	

	return 0;
} 
