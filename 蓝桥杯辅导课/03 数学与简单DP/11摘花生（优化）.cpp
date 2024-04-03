#include<bits/stdc++.h>

using namespace std;

const int N=1003;

int t;
int n,m; 

int a[N][N];
int f[N][N];

//由递归可以看出，状态可以由两个维度表示，x 和 y 

//截止状态为i=n;j=m 

//目标值就是dfs的初始值a[1][1] 

//也可以截止状态i=1 j=1
//那么目标值就是i=n j=m  
int main()
{
	cin>>t;
	
	while(t--)
	{
		cin>>n>>m;
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&a[i][j]);
			}
			
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				f[i][j]=max(f[i-1][j]+a[i][j],f[i][j-1]+a[i][j]);
			}
		cout<<f[n][m]<<endl;
	}
	return 0;
}
