#include<bits/stdc++.h>

using namespace std;

const int N=22;

typedef pair<int,int> PII;

#define x first
#define y second

char g[N][N]; 

int n,m;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

queue<PII> q;

int bfs(int x,int y)
{
	int res=1;
	g[x][y]='#';
	q.push({x,y});
	while(q.size())
	{
		auto t=q.front();
		q.pop();
		int a=t.x,b=t.y;
		for(int i=0;i<4;i++)
		{
			int nx=a+dx[i];
			int ny=b+dy[i];
			if(g[nx][ny]=='#')continue;
			if(nx<=m && ny<=n && nx>=1 && ny>=1)
			{
				g[nx][ny]='#';
				res++;
				q.push({nx,ny});
			}
		}
	}
	return res;
} 

int main()
{

	while(cin>>n>>m)
	{
		if(m==0 && n==0)break;
		int ix,iy;
		for(int i=1;i<=m;i++)
		{
			scanf("%s",g[i]+1);
			for(int j=1;j<=n;j++)
			{
				if(g[i][j]=='@')ix=i,iy=j;
			}
			//puts(g[i]+1);
		}

		cout<<bfs(ix,iy)<<endl;
		
	}
	
}
