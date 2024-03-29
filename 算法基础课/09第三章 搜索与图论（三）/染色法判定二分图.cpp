//二分图
//染色法判断二分图：深度优先遍历 
//而深度优先遍历的复杂度是线性的
//时间复杂度：O（n+m）
 
//二分图中不含有奇数环 
 
 
//染色法 
//for(i=1;i<=n;i++)
//	if i 未染色
//		dfs(i)，全染色一遍;
//

#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10,M=2e5+10;

int n,m;

int h[N],e[M],ne[M],idx;//稀疏图用邻接表
int color[N];

void add(int a,int b)
{
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}


bool dfs(int u,int c)
{
	color[u]=c;
	for(int i=h[u];i!=-1;i=ne[i])
	{
		int j=e[i];
		if(!color[j])//如果还没有染色 
		{
			if(!dfs(j,3-c))return false;//染成另一种颜色 
		}
		else if(color[j]==c)
		{
			return false;
		}
	}
	return true; 
} 

int main()
{
	cin>>n>>m;
	
	memset(h,-1,sizeof h);
	
	while(m--)
	{
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);	
	}
	
	bool flag=true; 
	
	for(int i=1;i<=n;i++)
	{
		if(!color[i])//如果没被染过色,就染成第一种颜色 
		{
			if(!dfs(i,1))//(这一步完成了染色)dfs返回false就是有矛盾发生 
			{
				flag=false;
				break;
			}
		}
	}
	
	if(flag)puts("Yes");
	else cout<<"No"<<endl;
	
	return 0;
} 
		 
