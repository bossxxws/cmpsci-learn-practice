//����ͼ
//Ⱦɫ���ж϶���ͼ��������ȱ��� 
//��������ȱ����ĸ��Ӷ������Ե�
//ʱ�临�Ӷȣ�O��n+m��
 
//����ͼ�в����������� 
 
 
//Ⱦɫ�� 
//for(i=1;i<=n;i++)
//	if i δȾɫ
//		dfs(i)��ȫȾɫһ��;
//

#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10,M=2e5+10;

int n,m;

int h[N],e[M],ne[M],idx;//ϡ��ͼ���ڽӱ�
int color[N];

void add(int a,int b)
{
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}


bool dfs(int u,int c)
{
	color[u]=c;
	for(int i=h[u];i!=-1;i=ne[i])
	{
		int j=e[i];
		if(!color[j])//�����û��Ⱦɫ 
		{
			if(!dfs(j,3-c))return false;//Ⱦ����һ����ɫ 
		}
		else if(color[j]==c)
		{
			return false;
		}
	}
	return true; 
} 

int main()
{
	cin>>n>>m;
	
	memset(h,-1,sizeof h);
	
	while(m--)
	{
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);	
	}
	
	bool flag=true; 
	
	for(int i=1;i<=n;i++)
	{
		if(!color[i])//���û��Ⱦ��ɫ,��Ⱦ�ɵ�һ����ɫ 
		{
			if(!dfs(i,1))//(��һ�������Ⱦɫ)dfs����false������ì�ܷ��� 
			{
				flag=false;
				break;
			}
		}
	}
	
	if(flag)puts("Yes");
	else cout<<"No"<<endl;
	
	return 0;
} 
		 
