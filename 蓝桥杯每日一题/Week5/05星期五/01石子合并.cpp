#include<bits/stdc++.h>

using namespace std;

const int N=303;

int a[N];

int n;

int f[N][N];//所有将区间i~j合并成一堆的集合里面的最小值 

int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]+=a[i-1];
	}
	//memset(f,0x3f,sizeof f); 
	for(int len=2;len<=n;len++)//先枚举区间长度 
		for(int i=1;i+len-1<=n;i++)//再枚举左端点（右端点自动算出来--j） 
		{
			int j=i+len-1;
			f[i][j]=1e8;//由于要求最小值，我们先给这个状态一个比较大的值 
			for(int k=i;k<=j;k++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+a[j]-a[i-1]);	
			}
		}
	
	cout<<f[1][n];//合并1~n所需要的体力集合中最小的值 
	return 0;
} 
