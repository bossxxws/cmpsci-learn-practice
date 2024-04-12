#include<bits/stdc++.h>

using namespace std;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

typedef pair<int,int> PII;

#define x first
#define y second

const int N=203;


char g[N][N];
int st[N][N];
//队列的空间要开大点，足够用 
int d[N][N];

int r,c;

int m;

int bfs(int x,int y)
{
    queue<PII> q;
    q.push({x,y});
	d[x][y]=0;
	while(q.size())
	{
		auto t=q.front();
		q.pop();
		int a=t.x,b=t.y;
		//g[a][b]='#';
		for(int i=0;i<4;i++)
		{
			int nx=a+dx[i];
			int ny=b+dy[i];
			if(g[nx][ny]=='#')continue;
			
			if(g[nx][ny]=='.')
			{
				d[nx][ny]=d[a][b]+1;
				q.push({nx,ny});
				g[nx][ny]='#';
			}
			
			if(g[nx][ny]=='E')
			{
                return d[a][b]+1;
			}
		}
			//cout<<tt<<endl;
	}
	return -1;
}

int main()
{
	scanf("%d",&m);
	
	while(m--)
	{
	   	//memset(d,0,sizeof d);
	   	memset(g,'#',sizeof g);
		scanf("%d%d",&r,&c);
		//cout<<r<<" "<<c;
		int ix,iy;
		for(int i=1;i<=r;i++)
			{
				scanf("%s",g[i]+1);
				for(int k=1;k<=c;k++)
				{
					if(g[i][k]=='S')
					{
						ix=i,iy=k;
						//cout<<ix<<" "<<iy<<endl;
					}
				}
			}//读入地图,找出初始位置 
			
		//for(int i=1;i<=r;i++)puts(g[i]+1);
		//cout<<111<<ix<<" "<<iy<<endl;
		int t=bfs(ix,iy);
		if(t==-1)cout<<"oop!"<<endl;
		else cout<<t<<endl; 
		//memset(d,0,sizeof d);
	}
	return 0;
}
