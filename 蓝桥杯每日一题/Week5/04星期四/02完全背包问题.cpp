#include<bits/stdc++.h>

using namespace std;

const int N=1003;

int v[N],w[N];

int f[N][N];//从前i种中取，且总体积不超过j 

int main()
{
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&v[i],&w[i]);
	}
	
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
		{
			f[i][j]=f[i-1][j];
			if(j>=v[i])f[i][j]=max(f[i][j],f[i][j-v[i]]+w[i]);//因为是max，所以没有不取的情况 
		}
	cout<<f[n][m];
	return 0;
}
/*
4 5
1 2
2 4
3 4
4 5

10

*/
