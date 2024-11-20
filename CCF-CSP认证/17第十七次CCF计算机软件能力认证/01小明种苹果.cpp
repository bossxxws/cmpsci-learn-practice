#include<bits/stdc++.h>

using namespace std;

int n,m;

const int N=1003;

int d[N][N]; 
int a[N];
int s[N];
int sum;
int mind=1e9;
int minidx;
int main()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)//第i棵果树 
	{
		cin>>a[i];//第i棵果树的初始数量 
		s[i]=s[i-1]+a[i];
		for(int j=1;j<=m;j++)
		{
			cin>>d[i][j];
			d[i][j]+=d[i][j-1];//前缀和表示变化量 
		}
		sum+=d[i][m];//总变化量 
		if(d[i][m]<mind)
		{
			mind=d[i][m];
			minidx=i;
		}
		
	}
	
	cout<<sum+s[n];
	cout<<" "<<minidx<<" ";
	cout<<abs(d[minidx][m]);
	
	
	return 0;
}
