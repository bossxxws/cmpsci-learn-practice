#include<bits/stdc++.h>

using namespace std;

const int N=103;

const int V=103;

int w[N],v[N];

vector<int>g[N];

int n,m,root;

int f[N][N];

void dfs(int x)
{
	for(int i=v[x];i<=m;i++)f[x][i]=w[x];
	for(int i=0;i<g[x].size();i++)
	{
		int y=g[x][i];
		dfs(y);
		for(int j=m;j>=v[x];j--)
		{
			for(int k=0;k<=j-v[x];k++)
			{
				f[x][j]=max(f[x][j],f[x][j-k]+f[y][k]);
			}
		}
	}
}

int main()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		int father;
		cin>>v[i]>>w[i]>>father;
		if(father==-1)root=i;
		else g[father].push_back(i);
	}
	
	dfs(root);
	
	cout<<f[root][m];

    return 0;
}

