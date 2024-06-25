#include<bits/stdc++.h>

using namespace std;

int n,m;


int sidx,sidy;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

const int N=1000+5;

char a[N][N];

bool flag; 
void dfs(int x,int y)
{

	if( (x==n || y==m || x==1 || y==1) && a[x][y]=='*')
	{
		flag=true;
	}
	a[x][y]='#';
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=1 && nx<=n && ny>=1 && ny<=m && a[nx][ny]=='*')
		{
			dfs(nx,ny);
		}
	}
}

int main()
{
	while(cin>>n>>m)
	{
		//随机挑选起点为sidx，sidy 
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		
		for(int i=1;i<=m;i++)
		{
			if(a[n][i]=='*')
			{
				sidx=n;sidy=i;
			}
			if(a[1][i]=='*')
			{
				sidx=1;sidy=i;
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(a[j][1]=='*')
			{
				sidx=j;sidy=1;
			}
			if(a[j][m]=='*')
			{
				sidx=j;sidy=m;
			}
		}
			
		a[sidx][sidy]='#';
		flag=false;
		
		dfs(sidx,sidy);
		
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}	
}
