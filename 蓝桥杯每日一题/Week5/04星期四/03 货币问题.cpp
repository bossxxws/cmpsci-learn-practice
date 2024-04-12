#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N=10003;

int kind[28];

LL f[N][N];//取前i种，并且最终面值为j的取法种类 

int main()
{
	int v,n;
	cin>>v>>n;
	for(int i=1;i<=v;i++)
	{
		scanf("%d",&kind[i]);
	}
	f[0][0]=1;
	for(int i=1;i<=v;i++)
		for(int j=0;j<=n;j++)
		{
			f[i][j]+=f[i-1][j];
			if(j>=kind[i])f[i][j]+=f[i][j-kind[i]];//因为是+，所以有不取的情况 
		}
	//cout<<f[2][0];
	cout<<f[v][n];
	return 0;
 } 
