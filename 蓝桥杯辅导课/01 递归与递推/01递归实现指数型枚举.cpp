#include<bits/stdc++.h>

using namespace std;

const int N=16;

int n;

int st[N];

//ö�ٵ���uλ 
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
	
	//������֧
	
	//��һ����֧����ѡ����2��ǲ�ѡ�� 
	
	st[u]=2;
	dfs(u+1);
	st[u]=0;
	
	//�ڶ�����֧��ѡ(1���ѡ) 
	
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
