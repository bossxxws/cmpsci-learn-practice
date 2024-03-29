#include<bits/stdc++.h>

using namespace std;

int n;

const int N=10;

char g[N][N];

bool col[N],dg[N],undg[N];
//对于n*n
//对角线：x+y
//反对角线：x-y+n
void dfs(int u)//u代表枚举到哪一行 
{
	if(u==n)//找到一种方案 
	{
		for(int i=0;i<n;i++)puts(g[i]);
		puts("");
		return ;
	}
	for(int i=0;i<n;i++)//枚举列 
	{
		 if(!col[i]&&!dg[u+i]&&!undg[u-i+n])
		 {
		 	g[u][i]='Q';
		 	col[i]=dg[u+i]=undg[u-i+n]=true;
		 	dfs(u+1);
		 	col[i]=dg[u+i]=undg[u-i+n]=false;
		 	g[u][i]='.';
		 }
	}
}
int main()
{
	cin>>n;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)g[i][j]='.';
	
	dfs(0);
	
	return 0;	
} 
