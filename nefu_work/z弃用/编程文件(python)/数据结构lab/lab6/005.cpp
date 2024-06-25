#include<bits/stdc++.h>

//完全背包问题 
//每一个物品只可以取一个 
 
using namespace std;

const int V=20003;

const int N=31;

int f[N][V];

int w[N];

int n,v;

int main()
{
	cin>>v>>n;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=v;j++)
		{
			
			f[i][j]=f[i-1][j];//不选i的情况 
			
			if(j>=w[i])f[i][j]=max(f[i][j],f[i-1][j-w[i]]+w[i]);
			
//			for(int k=0;k*w[i]<=j;k++)//选i的情况 
//			{
//				f[i][j]=max(f[i][j],f[i-1][j-k*w[i]]+k*w[i]);
//				cout<<f[i][j]<<endl;
//			}

		}	
	}	
	
	//cout<<f[n][v]<<endl;
	cout<<v-f[n][v]<<endl;
	return 0;
}