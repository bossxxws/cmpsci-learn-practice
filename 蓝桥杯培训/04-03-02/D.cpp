//我们发现每个连通块中能到达的点是一样的 
#include<bits/stdc++.h>

using namespace std;

const int N=1001;
const int M=1e6+10;

int n,m;

int q[M];
char g[N][N];
int vis[N][N];
int cnt=0,flag[N][N],ans[N*N];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

vector<int>r;

void dfs(int x,int y)
{
	vis[x][y]=1;
	flag[x][y]=cnt;//标记x，y这个点属于第cnt个连通块
	ans[flag[x][y]]++;//第cnt个连通块的面积+1 
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=1 && nx<=n && ny>=1 && ny<=n && !vis[nx][ny] && g[nx][ny]!=g[x][y])
		{
			dfs(nx,ny);
		}
	}
}

int main()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>g[i][j];
	

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(!vis[i][j])//如果没有访问过那就是其他的连通块 
			{
				cnt++;
				dfs(i,j);
			}
		}
		
	while(m--)
	{
		int o,p;
		cin>>o>>p;
		printf("%d\n",ans[flag[o][p]]);
	} 
	return 0;
}
