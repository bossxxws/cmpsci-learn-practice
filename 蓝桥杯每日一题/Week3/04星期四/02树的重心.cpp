#include<bits/stdc++.h>
/*
9
1 2
1 7
1 4
2 8
2 5
4 3
3 9
4 6
*/
using namespace std;

const int N=1e5+3,M=2*N;

bool st[N];
int h[N],e[M],ne[M],idx=0;
//h[N]存的是邻接表表头，e存的是值，ne存的是next指针 
//e是用到第几个的编号 

int n;
int ans=N;

//add里面a是头,b是插入元素 
void add(int a,int b)
{
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;//把idx赋值给h[a]，然后++ 
} 
	
int dfs(int u)
{
	st[u]=true;
	int sum=1;//当前已经有一个点u 
	int res=0;
	for(int i=h[u];i!=-1;i=ne[i])
	{
		int j=e[i];
		if(!st[j])
		{
			int s=dfs(j);//以j为根节点的连通块的节点数量（包括j）
			res=max(res,s); 
			sum+=s;			
		}	
	}
	res=max(res,n-sum);
	ans=min(ans,res);
	return sum;
} 
	
int main()
{
	cin>>n;
	memset(h,-1,sizeof h);
	for(int i=1;i<=n-1;i++)
	{
		int a,b; 
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	dfs(1);
	cout<<ans;
	return 0;	
} 
