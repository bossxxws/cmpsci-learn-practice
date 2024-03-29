#include<bits/sdtc++.h>

using namespace std;

const int N=301;

int t;
int n;

int res;

int dk[2]={1,-1};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int st[N][N];

void check(int x,int y)
{
	
} 

void bfs(int x,int y)
{
	//if(g[x][y]=='*')return ;
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=0 && ny>=0 && nx<n && ny<=n && !st[nx][ny] && g[nx][ny]=='.' && check(nx,ny))//ÉÏÏÂ×óÓÒ 
		{
			st[nx][ny]=1;
			dfs(nx,ny);
		}

		
	}
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			int kx=x+dx[i]+dk[j];
			int ky=y+dx[i]+dk[j];
			if(kx>=0 && ky>=0 && kx<n && ky<n &&!st[nx][ny] && g[kx][ky]=='.')
			{
				st[kx][ky]=1;
				dfs(kx,ky);
			}
		}	

	}
	
	
	
	
}

char g[N][N];

int main()
{
	cin>>t;
	int cnt=1;
	res=0;
	while(t--)
	{
		cin>>n;
		
		for(int i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				scanf("%d",&g[i][j]);	
			}	
			
		for(int i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(!st[i][j] && g[i][j]=='.')
				{
					bfs(i,j);
					res++;	
				}	
			}	
			
		printf("Case #%d: %d",&cnt,&res);
		
		cnt++;	
	}	
	
	return 0;
}
