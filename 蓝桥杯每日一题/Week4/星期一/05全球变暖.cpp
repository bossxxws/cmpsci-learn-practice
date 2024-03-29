//Ë¼Â·´íÁË 
#include<bits/stdc++.h>

using namespace std;

const int N=1004;

char g[N][N];
int n;

typedef pair<int,int> PII;

queue<PII>q;
 
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int vis[N][N];

void bfs()
{
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
		{
			if(!vis[i][j] && g[i][j]=='.') 
			{
				for(int k=0;k<4;k++)
				{
					int nx=i+dx[k];
					int ny=j+dy[k];
					if(nx>=0 && ny>=0 && nx<n && ny<n  && g[nx][ny]=='#')
					{
						//!!!!!
						vis[nx][ny]=1;
						g[nx][ny]='.';
						//£¡£¡£¡£¡ 
					}
				}
			}
		}
}

int main()
{
	cin>>n;	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cin>>g[i][j];
		}
	
	bfs();
	
	int res=0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			//if(g[i][j]=='#')res++;
			cout<<g[i][j];
		}
		cout<<endl;
	}

	cout<<res;
	return 0;
}
