#include<bits/stdc++.h>

using namespace std;

const int N=13;

int a[N][N];

int f[N][N]; 

int main()
{
	//只能向右下角行走
	
	int n;
	cin>>n;
	
	int r,c,v;
	
	while(cin>>r>>c>>v && r&&c&&v)
	{
		
		a[r+1][c+1]=v;//行和列编号从1开始 
		
	} 
	
	int res=0;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			bool flag=false;
			
			if(f[i][j]>=max(f[i-1][j]+a[i][j],f[i][j-1]+a[i][j]))flag=true;
			
			f[i][j]=max(f[i-1][j]+a[i][j],f[i][j]);
			f[i][j]=max(f[i][j-1]+a[i][j],f[i][j]);
			
			if(flag)continue;
			
			if(f[i-1][j]>=f[i][j-1])a[i-1][j]=0;//,cout<<i<<" "<<j<<endl;
			else a[i][j-1]=0;
			
		}
	
	res+=f[n][n];
	
	memset(f,0,sizeof f);
	
	cout<<res<<endl;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			
			f[i][j]=max(f[i-1][j]+a[i][j],f[i][j]);
			f[i][j]=max(f[i][j-1]+a[i][j],f[i][j]);
			
		}
		
	res+=f[n][n];
	
	cout<<res;
	return 0;
} 
