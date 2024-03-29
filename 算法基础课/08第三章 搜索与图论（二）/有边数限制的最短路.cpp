//bellman-ford �㷨 �������������㷨��   O(nm)
//for n ��
//    for ���б� a��b��w
//			dist[b =min(dist[b],dist[a]+w);
//dist[b]<=dist[a]+w;(���ǲ���ʽ)



#include<bits/stdc++.h> 

using namespace std;

const int N=510,M=1e4+10;

int n,m,k;//n����m���ߣ���ྭ��k���ߣ�����������µ����·�� 
int dist[N],backup[N];//���� ���� 

struct Edge
{
	int a,b,w;//��� �յ� Ȩ�� 
}edges[M];

int bellman_ford()
{
    memset(dist,0x3f3f3f3f,sizeof dist);
    dist[1]=0;
    for(int i=0;i<k;i++)//����k�� 
	{
		memcpy(backup,dist,sizeof dist);//ÿ�ε���ǰ����һ�Σ���ֹ����(��֤ÿ������ͬ�Ĳ���)
		for(int j=0;j<m;j++)
		{
			int a=edges[j].a,b=edges[j].b,w=edges[j].w;
			dist[b]=min(dist[b],backup[a]+w);
			
		} 
	}
	if(dist[n]>0x3f3f3f3f/2)return 0x3f3f3f3f;
	return dist[n];
		
}

int main()
{
	cin>>n>>m>>k;
	
	for(int i=0;i<m;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		edges[i]=
		{
			a,b,w
		};
	}
	int t= bellman_ford();
	if(t==0x3f3f3f3f)cout<<"impossible"<<endl;
	else cout<<t<<endl;
	return 0;
}
