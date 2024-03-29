#include<bits/stdc++.h>

using namespace std;

const int N=10;

int n;

char g[N][N];//方案 
bool col[N],dg[N],udg[N];//同一列、正对角线、反对角线各开一个 


void dfs(int u)
{
	if(u==n)//找到一种方案 
	{
		for(int i=0;i<n;i++)puts(g[i]);
		puts("");
		return ;
	}
	for(int i=0;i<n;i++)
	{
		if(!col[i] && !dg[u+i] && !udg[-u+i+n])//+n为偏移量，如果为负数，对角线移动到棋盘外，令其移动到棋盘低位
		{
			g[u][i]='Q';
			col[i]=dg[u+i]=udg[-u+i+n]=true;
			dfs(u+1);//放一个进下一层，直到放n个
			col[i]=dg[u+i]=udg[-u+i+n]=false;//回溯 
			g[u][i]='.';//恢复现场 
		}
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
	
	dfs(0);
	
	return 0;
} 
