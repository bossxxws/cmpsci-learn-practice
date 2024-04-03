#include<bits/stdc++.h>

using namespace std;

const int MOD=1000000007;

const int N=52;

typedef long long LL; 

int n,m,k;

int a[N][N];

LL ans=0; 

int dx[]={1,0};
int dy[]={0,1};

void dfs(int x,int y,int maxvalue,int cnt)
{
	if(x==n && y==m && cnt==k)
	{
		ans++;
		ans=ans%MOD;
	}
	
	for(int i=0;i<2;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<=n && ny<=m && a[nx][ny]>maxvalue)dfs(nx,ny,a[nx][ny],cnt+1),dfs(nx,ny,maxvalue,cnt);//拿起和不拿 
		else if(nx<=n && ny<=m)dfs(nx,ny,maxvalue,cnt);//不拿 
	}
	
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}


	dfs(1,1,a[1][1],1);
	dfs(1,1,-1,0);
	cout<<ans; 
	
	return 0;
};
/*
2 2 2
1 2
2 1

2

2 3 2
1 2 3
2 1 5


14

*/


/*
for(int i=1;i<=n;i++)
{
	for(int j=1;j<=m;j++)
	{
		cout<<a[i][j]<<" ";
	} 
	cout<<endl;
}
*/

