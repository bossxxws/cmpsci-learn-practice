#include<bits/stdc++.h>

using namespace std;

const int N=26;

int n,m;

int f[N],st[N];

//u��������ö���˼��� 
void dfs(int u,int star)
{
	//��������ѡ��u����(�Ѿ�ѡ��u-1����)��ʣ�»���n-star+1�������������ȫ������ҲС��m
	//��ôֱ��ִ�м�֦��return 
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
		f[u]=0;//����ʡ�ԣ������׼�ĽǶ�Ҫ�У��ָ��ֳ��� 
	} 
}

int main()
{
	cin>>n>>m;
	
	dfs(1,1); 
	return 0;
} 
