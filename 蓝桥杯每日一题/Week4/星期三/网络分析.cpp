#include<bits/stdc++.h>

using namespace std;

const int N=2e4+10,M=N<<1;

int p[N];

int h[M],e[M],ne[M],idx;

int add(int a,int b)
{
	e[idx]=b;//ֵ�浽e�idx��e�ı�ţ� 
	ne[idx]=h[a];//d�ı�ŵ���һ��ָ��h��a��ָ��ı�� 
	h[a]=idx++;//h��a��ָ��b�ı�� 
}

int f[N];//�洢��Ϣ 

int n,m;

int find(int x)
{
	if(x!=p[x])p[x]=find(p[x]);
	return p[x];
}

void merge(int a,int b,int &root)
{
	a=find(a);
	b=find(b);
	if(a!=b)
	{
		p[a]=p[b]=root;
		add(root,a);
		add(root,b);
		root++;
	}
}

void dfs(int son,int father)
{
	f[son]+=f[father];
	for(int i=h[son];i!=-1;i=ne[son])
	{
		int j=e[i];
		dfs(j,son);
	}
}

int main()
{
	memset(h,-1,sizeof h);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		p[i]=i;
	}
	 
	int root=n+1; 
	while(m--)
	{
		int t,a,b;
		cin>>t;
		cin>>a>>b;
				
		if(t==1)
		{
			merge(a,b,root);
		}
		else
		{
			a=find(a);
			f[a]+=b;
		}
		
	}
	
	for(int i=n+1;i<root;i++)dfs(i,0);//��ÿ�����ڵ��ֵ���ݵ�ÿ���������
	for(int i=1;i<=n;i++)cout<<f[i]<" ";
	return 0;
}
