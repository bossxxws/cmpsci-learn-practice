//��С������ 
//��³˹�����㷨 Kruskal  
//ʱ�临�Ӷȣ� O��mlogm��
//---------ϡ��ͼ--------- 

//1.�����б߰�Ȩ�ش�С��������   

//2. ö��ÿ���ߣ�a-b Ȩ����c
//���a��b����ͨ���������߼��뵽������ 

#include<bits/stdc++.h>

using namespace std;

const int N=200000+10;

int n,m;

int p[N];//���鼯 


struct Edge
{
	int a,b,w;
	bool operator<(const Edge &W)const
	{
		return w<W.w;
	}
}edges[N];

int find(int x)
{
	if(x!=p[x]) p[x]=find(p[x]);
	return p[x];
}

int main()
{
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		edges[i]={a,b,w};
	}
	
	sort(edges,edges+m);
	
	for(int i=1;i<=n;i++)
	{
		p[i]=i;//һ��ʼ���鼯�е�ÿ���㶼������ͨ��
	}
	
	int res=0,cnt=0;
	
	for(int i=0;i<m;i++)
	{
		int a=edges[i].a,b=edges[i].b,w=edges[i].w;
		a=find(a);
		b=find(b);
		if(a!=b)
		{
			
			p[a]=b;//���鼯�еĺϲ��������൱�ڼ��뵽��С��������һ���֣��ʼÿ�����ֲ�һ�����ӣ�
			//�����Ϊһ����С����������Ϊһ����
			//���û�г�Ϊһ����������С������
			
			res+=w;//��С��������Ȩ 
			cnt++;//����ߵ���Ŀ 
			
		}
	}
	
	if(cnt<n-1)puts("impossible");//û�г�Ϊһ���֣�����ĵ�С��n-1��
	else cout<<res<<endl;
	
}
