#include<bits/stdc++.h>

using namespace std;

const int N=103;

int n,m;

typedef pair<int,int> PII; 

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int g[N][N];
int vis[N][N];

int hh=0,tt=0;
PII q[N*N];

void bfs()
{
	q[0]={1,1};
	while(hh<=tt)
	{
		PII t=q[hh++];//pop
		for(int i=0;i<4;i++)
		{
			int nx=t.first+dx[i];	
			int ny=t.second+dy[i];
			if(nx>=1 && ny>=1 && nx<=n && ny<=m && vis[nx][ny]==-1 && g[nx][ny]==0)
			{
				vis[nx][ny]=vis[t.first][t.second]+1;
				q[++tt]={nx,ny};//enqueue
			}
		}	
	}	
	
}

int main()
{
	cin>>n>>m;
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//Ç§Íò±ğÍüÁËmemset
	memset(vis,-1,sizeof vis);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&g[i][j]);
		}//read graph
	
	bfs(); 
	
	cout<<vis[n][m]+1;
	
	return 0;	
} 
/*
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0

8

*/
