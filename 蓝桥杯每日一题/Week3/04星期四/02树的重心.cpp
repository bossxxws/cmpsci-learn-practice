#include<bits/stdc++.h>
/*
9
1 2
1 7
1 4
2 8
2 5
4 3
3 9
4 6
*/
using namespace std;

const int N=1e5+3,M=2*N;

bool st[N];
int h[N],e[M],ne[M],idx=0;
//h[N]������ڽӱ��ͷ��e�����ֵ��ne�����nextָ�� 
//e���õ��ڼ����ı�� 

int n;
int ans=N;

//add����a��ͷ,b�ǲ���Ԫ�� 
void add(int a,int b)
{
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;//��idx��ֵ��h[a]��Ȼ��++ 
} 
	
int dfs(int u)
{
	st[u]=true;
	int sum=1;//��ǰ�Ѿ���һ����u 
	int res=0;
	for(int i=h[u];i!=-1;i=ne[i])
	{
		int j=e[i];
		if(!st[j])
		{
			int s=dfs(j);//��jΪ���ڵ����ͨ��Ľڵ�����������j��
			res=max(res,s); 
			sum+=s;			
		}	
	}
	res=max(res,n-sum);
	ans=min(ans,res);
	return sum;
} 
	
int main()
{
	cin>>n;
	memset(h,-1,sizeof h);
	for(int i=1;i<=n-1;i++)
	{
		int a,b; 
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	dfs(1);
	cout<<ans;
	return 0;	
} 
