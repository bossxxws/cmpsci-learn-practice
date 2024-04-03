#include<bits/stdc++.h>

using namespace std;

const int N=16;

int n;

int st[N];

//枚举到第u位 
void dfs(int u)
{
	if(u>n)
	{
		for(int i=1;i<=n;i++)
		{
			if(st[i]==1)printf("%d ",i);	
		}
		cout<<endl;
		return ;
	}
	
	//两个分支
	
	//第一个分支，不选（用2标记不选） 
	
	st[u]=2;
	dfs(u+1);
	st[u]=0;
	
	//第二个分支，选(1标记选) 
	
	st[u]=1;
	dfs(u+1);
	st[u]=0;
	return ;
}

int main()
{
	cin>>n;
	
	dfs(1);
	
	return 0;
}
