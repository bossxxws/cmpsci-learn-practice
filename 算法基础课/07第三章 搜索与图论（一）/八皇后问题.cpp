#include<bits/stdc++.h>

using namespace std;

const int N=10;

int n;

char g[N][N];//���� 
bool col[N],dg[N],udg[N];//ͬһ�С����Խ��ߡ����Խ��߸���һ�� 

//ÿ�εݹ鶼������һ�з��ûʺ� 
void dfs(int u)
{
	if(u==n)//�ҵ�һ�ַ��� 
	{
		for(int i=0;i<n;i++)puts(g[i]);
		puts("");
		return ;
	}
	for(int i=0;i<n;i++)
	{
		if(!col[i] && !dg[u+i] && !udg[-u+i+n])//+nΪƫ���������Ϊ�������Խ����ƶ��������⣬�����ƶ������̵�λ
		{
			g[u][i]='Q';//uΪ�У�iΪ�� 
			col[i]=dg[u+i]=udg[-u+i+n]=true;
			dfs(u+1);//����һ�з�һ���ʺ�ֱ����n��
			col[i]=dg[u+i]=udg[-u+i+n]=false;//���� 
			g[u][i]='.';//�ָ��ֳ� 
		}
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			g[i][j]='.';
		}
	}
	
	dfs(0);
	
	return 0;
} 
