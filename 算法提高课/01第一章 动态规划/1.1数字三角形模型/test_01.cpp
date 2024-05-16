#include<bits/stdc++.h>

using namespace std;

const int N=100;

int h[N],e[N],ne[N],idx;

int vis[N];

void add(int a,int b)
{
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}

void dfs(int s)
{	
	for(int i=s;i!=-1;i=ne[i])
	{
		if(!vis[e[i]])
		{
			vis[e[i]]=1;
			dfs(h[e[i]]);
			cout<<e[i]<<endl;
		}
	
	}
}

int main()
{
	memset(h,-1,sizeof h);
	
	add(1,2);
	add(2,3);
	add(3,1);
	add(2,4);


	dfs(h[1]);
    return 0;
}
