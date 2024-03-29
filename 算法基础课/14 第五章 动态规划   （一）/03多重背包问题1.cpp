//c++一秒最多算一亿次 
//01背包  ：f[i,j]=max(f[i-1,j], **f[i-1,j-v]** +w])
//完全背包：f[i,j]=max(f[i-1,j], ** f[i,j-v] ** +w) 
//只有一点不一样
#include<bits/stdc++.h>

using namespace std;

const int N=110;

int n,m;

int v[N],w[N],s[N];
int f[N][N];

/*

f[i,j]=max(f[i-1][j-v[i]*k] + w[i] * k);k = 0,1,2.....s[i]

*/
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>v[i]>>w[i]>>s[i];
	
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int k=0;k*v[i]<=j && k<=s[i];k++)
				f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);

		
	cout<<f[n][m];
	return 0;
} 
