#include<bits/stdc++.h>

using namespace std;

const int N=1003;

int w[N],v[N];

int f[N][N];//选前i种，并且体积不超过j的价值的最大值 

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
			if(j>=v[i])f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);
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

8

*/
