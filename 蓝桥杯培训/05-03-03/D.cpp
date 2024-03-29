#include<bits/stdc++.h>

using namespace std;

const int N=1005;

int n,m;
int t=max(n,m);
int g[N][N];
int vis[N][N],visx[N][N],visy[N][N];
int dx[4]={1,-1};
int dy[4]={1,-1};


int dfsx(int x,int y)
{
	int res=0;
	res+=1;
	//cout<<"+"<<endl;
	visx[x][y]=1;
	if(res==t)return res;
	for(int i=0;i<2;i++)
	{
		int nx=x+dx[i];
		if(!visx[nx][y] && nx>=1 && nx<=n && y>=1 && y<=m && g[x][y]==g[nx][y])
		{
			res+=dfsx(nx,y);//cout<<"yes"<<res<<endl;
		}
	}
	//cout<<"res=="<<res<<endl;
	return res;
}

int dfsy(int x,int y)
{
	int res=0;
	res+=1;
	//cout<<"+"<<endl;
	visy[x][y]=1;
	if(res==t)return res;
	for(int i=0;i<2;i++)
	{
		int ny=y+dy[i];
		if(!visy[x][ny] && x>=1 && x<=n && ny>=1 && ny<=m && g[x][y]==g[x][ny])
		{
			res+=dfsy(x,ny);//cout<<"yes"<<res<<endl;
		}
	}
	//cout<<"res=="<<res<<endl;
	return res;
}

int main()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>g[i][j];	
		} 

	int res=-1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int t;
			if(!vis[i][j])
			{
				int x=dfsx(i,j);
				int y=dfsy(i,j);
				t=max(x,y);
				vis[i][j]=1;
			}
			//cout<<t<<endl;
			res=max(res,t);
		}

	
	cout<<res;
	return 0;
}
