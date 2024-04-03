#include<bits/stdc++.h>
//求最大的，就收缩左边界，这里所以l=mid 
using namespace std;

const int N=1e5+5;

int n,k; 

int a[N];

int l[N],b[N]; 

bool check(int x)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cnt+=(l[i]/x)*(b[i]/x);
	}
	//cout<<x;
	return cnt>=k;
}

int main()
{
	cin>>n>>k;
	//读入巧克力数据 
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&l[i],&b[i]);
	}
	
	int l=1,r=N;
	
	while(l<r)
	{
		int mid=l+r+1>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	} 
	
	cout<<l;
	return 0;
}
