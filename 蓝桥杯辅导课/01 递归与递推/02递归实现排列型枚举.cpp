#include<bits/stdc++.h>

using namespace std;

const int N=11;

int n;

int path[N];

int st[N];

void dfs(int u)//u表示当前递归到第u位了 
{
	//如果u大于n则表示已经填满了，输出 
	if(u>n)
	{
		for(int i=1;i<=n;i++)
		{
			cout<<path[i]<<" ";
		}
		cout<<endl;
	}
	
	
	for(int i=1;i<=n;i++)
	{
		//如果数字i还没有被用过 
		if(!st[i])
		{
			//用一下i这个数字 
			path[u]=i;
			//标记为用过后进入递归 
			st[i]=1;
			//进入递归 
			dfs(u+1);
			//恢复现场 
			st[i]=0;
		}		
	} 
}

int main()
{
	cin>>n;
	
	dfs(1);
	return 0;
}
