#include<bits/stdc++.h>

using namespace std;

int n;

const int N=10;

char g[N][N];

bool col[N],dg[N],undg[N];
//����n*n
//�Խ��ߣ�x+y
//���Խ��ߣ�x-y+n
void dfs(int u)//u����ö�ٵ���һ�� 
{
	if(u==n)//�ҵ�һ�ַ��� 
	{
		for(int i=0;i<n;i++)puts(g[i]);
		puts("");
		return ;
	}
	for(int i=0;i<n;i++)//ö���� 
	{
		 if(!col[i]&&!dg[u+i]&&!undg[u-i+n])
		 {
		 	g[u][i]='Q';
		 	col[i]=dg[u+i]=undg[u-i+n]=true;
		 	dfs(u+1);
		 	col[i]=dg[u+i]=undg[u-i+n]=false;
		 	g[u][i]='.';
		 }
	}
}
int main()
{
	cin>>n;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)g[i][j]='.';
	
	dfs(0);
	
	return 0;	
} 
