#include<bits/stdc++.h>

using namespace std;

const int N=11;

int n;

int path[N];

int st[N];

void dfs(int u)//u��ʾ��ǰ�ݹ鵽��uλ�� 
{
	//���u����n���ʾ�Ѿ������ˣ���� 
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
		//�������i��û�б��ù� 
		if(!st[i])
		{
			//��һ��i������� 
			path[u]=i;
			//���Ϊ�ù������ݹ� 
			st[i]=1;
			//����ݹ� 
			dfs(u+1);
			//�ָ��ֳ� 
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
