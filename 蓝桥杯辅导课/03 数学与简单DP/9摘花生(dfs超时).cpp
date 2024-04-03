#include<bits/stdc++.h>

using namespace std;

const int N=1003;

int t;
int n,m; 

int g[N][N];

int dx[]={1,0};//i=0ÏòÏÂ 
int dy[]={0,1};//i=1ÏòÓÒ 

int ans=-1; 

void dfs(int x,int y,int cnt)
{
	if(x==n && y==m)
	{
		ans=max(cnt,ans);
	}
	
	for(int i=0;i<2;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		//cout<<1;
		if(nx>=1 && ny>=1 && nx<=n && ny<=m)dfs(nx,ny,cnt+g[nx][ny]);
	}
}

int main()
{
	cin>>t;
	while(t--)
	{
		scanf("%d%d",&n,&m);
		//cout<<n<<" "<<m<<endl;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&g[i][j]);
			}
		}

		dfs(1,1,g[1][1]);
		cout<<ans<<endl;
	}
	return 0;
}
