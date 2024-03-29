#include<bits/stdc++.h>

using namespace std;

const int N=101;

char g[N][N];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int cnt;

int n,m;//行列

//把当前坐标四周不是0的全部变成0 
void dfs(int x,int y)
{
	g[x][y]='0';
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=1 && nx<=n && ny>=1 && ny<=m && g[nx][ny]!='0')
		{
			dfs(nx,ny);
		}
	}
}

int main()
{
	while(cin>>n>>m)
	{
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				cin>>g[i][j];
			}
			
		cnt=0;
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(g[i][j]!='0')
				{
					cnt++;
					dfs(i,j);
				}
			}	
		
		cout<<cnt<<endl;
		
	}	
	
	
	
	return 0;
} 
