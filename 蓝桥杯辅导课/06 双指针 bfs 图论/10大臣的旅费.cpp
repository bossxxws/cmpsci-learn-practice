#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

typedef long long LL;

int h[2*N],e[2*N],ne[2*N],w[2*N],idx;//w������Ǳ�Ȩ 

int maxu,maxd=-1;

int n;
//���ڴ��׶�������һ������е�·����Ψһ��
//��������һ���� 
//���·��������ֱ��
//������ֱ����
//���Ҿ���ĳһ����Զ�ĵ�
//���������Զ�ĵ� �� ��Զ�ĵ� 

int add(int a,int b,int l)
{
	
	e[idx]=b;//e�洢idx��Ӧ�Ľڵ�� 
	w[idx]=l;//w����idx��Ӧ�ı�Ȩ 
	ne[idx]=h[a];
	h[a]=idx++;
	
}

void dfs(int son,int father,int d)
{
	for(int i=h[son];i!=-1;i=ne[i])
	{
		int j=e[i];
		int k=w[i];//ȡ���ڵ�źͶ�Ӧ��Ȩ��
		if(j==father)continue;
		if(maxd<k+d)
		{
			maxd=k+d;
			maxu=j;	
		} 
		dfs(j,son,d+k);//j��son���ӽڵ㣬���ﵹ����� ��Ϊ�˸��������룩 
	}
}


int main()
{
	cin>>n;
	memset(h,-1,sizeof h);
	for(int i=1;i<=n-1;i++)
	{
		int a,b,l;
		
		scanf("%d%d%d",&a,&b,&l);
		
		add(a,b,l);
		
		add(b,a,l);
		
	}
	
	dfs(1,-1,0);//�Ҳ����ڵĸ��ڵ㣨�Ҿ���1�ڵ���Զ�Ľڵ㣩 
	dfs(maxu,-1,0);//maxu��ʱ����1��Զ�Ľڵ� 
	//ͨ��maxu������Զ���� 
	LL sum=((LL)(1+10)+(maxd+10))*maxd/2;
	cout<<sum;
	return 0;
}
