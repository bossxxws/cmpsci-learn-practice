//dfs ���ÿռ��٣�Ϊn         ���ݽṹ��stack 
//bfs ���ÿռ�࣬Ϊ2��n�η�  ���ݽṹ��queue 

//������dfs������������dfs�������������������� 
#include<bits/stdc++.h>

using namespace std;

const int N=10;

int path[N];//�洢·�� 

bool st[N];//�������� 

int n; 

void dfs(int u)
{
	if(u==n)//u==n������������������ϣ�������� 
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
