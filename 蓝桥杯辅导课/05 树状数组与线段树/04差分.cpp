#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

int b[N];

int n,m;

int main()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	
	for(int i=n;i>=0;i--)b[i]-=b[i-1];
	
	while(m--)
	{
		int l,r,c;
		scanf("%d%d%d",&l,&r,&c);
		
		b[l]+=c;
		b[r+1]-=c;
	}
	
	for(int i=1;i<=n;i++)
	{
		b[i]+=b[i-1];
		cout<<b[i]<<" ";
	}
	
	
	return 0;
} 
