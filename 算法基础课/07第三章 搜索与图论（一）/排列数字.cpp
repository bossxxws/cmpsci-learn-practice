//dfs 所用空间少，为n         数据结构：stack 
//bfs 所用空间多，为2的n次方  数据结构：queue 

//本题用dfs来暴力搜索（dfs经常被用来暴力搜索） 
#include<bits/stdc++.h>

using namespace std;

const int N=10;

int path[N];//存储路径 

bool st[N];//用来回溯 

int n; 

void dfs(int u)
{
	if(u==n)//u==n则代表深度优先搜索完毕，可以输出 
	{
		for(int i=0;i<n;i++)cout<<path[i]<<" ";
		puts("");
		
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!st[i])
		{
			path[u]=i;
			st[i]=true;
			dfs(u+1);
			st[i]=false;
		}
	}
}

int main()
{
	cin>>n;
	
	dfs(0);
	
	return 0;
}
