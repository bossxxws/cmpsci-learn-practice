#include<bits/stdc++.h>

using namespace std;

const int N=20;

int n;
char g[N][N];
bool row[N],col[N],dg[N],udg[N];


void dfs(int x,int y,int s)
{
	if(y==n)y=0,x++;
	
	if(x==n)//x==n则表示已经枚举完最后一行了 
	{
		if(s==n)//摆的皇后的个数等于n 
		{
			for(int i=0;i<n;i++)puts(g[i]);
			puts("");
		}
		return ;
	}
	
	//不放皇后
	dfs(x,y+1,s);//直接枚举下一个格子 
	
	
	//放皇后 
	if(!row[x] && !col[y] && !dg[x+y] && !udg[x-y+n])
	{
		g[x][y]='Q';
		row[x]=col[y]=dg[x+y]=udg[x-y+n]=true;
		dfs(x,y+1,s+1);
		row[x]=col[y]=dg[x+y]=udg[x-y+n]=false;
		g[x][y]='.';
	}
	
		
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			g[i][j]='.';
		}
	}
	dfs(0,0,0);
	return 0;
}
