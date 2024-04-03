#include<bits/stdc++.h>

using namespace std;

const int N=1003;

int t;
int n,m; 

int a[N][N];

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
			
	    //洗数组
		for(int i=1;i<=n;i++)a[i][m+1]=0;
		for(int i=1;i<=m;i++)a[n+1][i]=0;
		
		//dp！
		for(int i=n;i>=1;i--)
			for(int j=m;j>=1;j--)
			{
				if(i==m && j==n)continue;
				
				a[i][j]=max(a[i+1][j]+a[i][j],a[i][j+1]+a[i][j]);
			}
		
		cout<<a[1][1]<<endl;
	}
	return 0;
}
