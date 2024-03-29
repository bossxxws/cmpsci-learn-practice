/*
״̬ѹ��N�ļ�����20

����˵N�Ƚ�С��ʱ����Կ���״̬ѹ��
 
״̬��ʾ��
	���ϣ�
			f[u][0]��ʾ����uΪ��������ѡ���Ҳ�ѡ��u�����ķ���
			f[u][1]��ʾ����uΪ��������ѡ����ѡ��u�����ķ��� 
	���ԣ�  MAX 

״̬���㣺
			f[u][0]���� ÿ���������ڵ�����״̬�е����ֵ ���
			f[u][1]���� ÿ���������ڵ��ֵ��ӣ���Ϊ����ѡ��˾������ֻ��һ��״̬�� 
			�ݹ鵽u������ʱ���ȵݹ鴦�����Ķ��ӣ��ȰѶ��Ӵ���� 

*/
#include<bits/stdc++.h>

using namespace std;

const int N=6010;

int n;

int happy[N]; 

int h[N],e[N],ne[N],idx;//�ڽӱ�洢

int f[N][2]; 

bool has_father[N];

void add(int a,int b)
{
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
} 

void dfs(int u)
{
	f[u][1]=happy[u];
	
	for(int i=h[u];i!=-1;i=ne[i])
	{
		int j=e[i];
		
		dfs(j);//�ȰѶ�����һ��
		
		f[u][0]+=max(f[j][0],f[j][1]);
		
		f[u][1]+=f[j][0]; 
	}
} 

int main()
{
	scanf("%d",&n);
	
	memset(h,-1,sizeof h); 
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&happy[i]);
	}
	
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		//b��a����˾
		has_father[a]=true; 
		add(b,a);
	}
	
	int root=1;
	
	while(has_father[root])root++;//һֱ������� 
	
	dfs(root);
	
	printf("%d",max(f[root][0],f[root][1]));
	//���ڵ��ϵ�����״̬��ȡ���ڵ㣬��ȡ���ڵ�
		
	return 0;
}
