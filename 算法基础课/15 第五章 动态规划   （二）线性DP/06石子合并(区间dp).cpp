#include<bits/stdc++.h>

using namespace std;

const int N=310;

int a[N]; 

int s[N];

int n;

int f[N][N]; 	 

int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	
	for(int len=2;len<=n;len++)//区间长度
		for(int i=1;i+len-1<=n;i++)
		{
			int l=i,r=i+len-1;//起点为i，长度为len 
			f[l][r]=1e9;
			//区间长度为1的时候不需要合并，代价为0，所以不需要枚举
			//直接从2开始枚举 
			for(int k=l;k<r;k++)
			{
				f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
			}
		} 
		
	
	cout<<f[1][n];
	return 0;
}
