#include<bits/stdc++.h>

using namespace std;

const int N=26;

int n,m;

int f[N],st[N];

//u代表现在枚举了几个 
void dfs(int u,int star)
{
	//假设正在选第u个数(已经选了u-1个数)，剩下还有n-star+1个数，如果就算全部加上也小于m
	//那么直接执行剪枝，return 
	if((u-1)+(n-star+1)<m) return ;
	if(u==m+1)
	{
		for(int i=1;i<=m;i++)
		{
			printf("%d ",f[i]);
		}
		cout<<endl;
		return ;
	}
	
	for(int i=star;i<=n;i++)
	{
		f[u]=i;
		dfs(u+1,i+1);
		f[u]=0;//可以省略，从最标准的角度要有（恢复现场） 
	} 
}

int main()
{
	cin>>n>>m;
	
	dfs(1,1); 
	return 0;
} 
