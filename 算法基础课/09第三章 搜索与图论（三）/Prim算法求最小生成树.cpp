//��С������ 
//���ذ�Prim�㷨 ���ذ�����ķ�㷨
//     ʱ�临�Ӷȣ�O(n**2) 
//---------����ͼ����---------
//�ڽӾ��� 

//�ҵ����ڼ����еģ�������ȷ����С����ĵ㣩��С��ŵĵ� 
//���ڼ����о��ǲ�ȷ����̾���ĵ� 



/*
��ʼ��dist��i��=������ 
for��i=0��i<n;i++�� 
{
	1.�ҵ��������������ĵ㣬����t
	2.��t�����������㵽--����--���Ͻ�˹�����ǵ����ľ��룩�ľ��� 
	3.��t�ӵ�st�st��t��=true�� 
}

*/


#include<bits/stdc++.h>

using namespace std;

int n,m;
const int N=510,INF=0x3f3f3f3f;
int g[N][N];
int dist[N];
int st[N];

int prim()
{
	memset(dist,0x3f,sizeof dist);
	int res=0;
	//n�ε���
	for(int i=0;i<n;i++)
	{
		int t=-1;
		for(int j=1;j<=n;j++)
		{
			if(!st[j] && (t==-1 || dist[t]>dist[j]))
			{
				t=j;		
			}
		}	
		
		if(i && dist[t]==INF) return INF;
		if(i) res+=dist[t]; 
		
		for(int j=1;j<=n;j++)dist[j]=min(dist[j],g[t][j]);
		

		st[t]=true;//�������ӵ������棬��Ϊ����һ���� 
	} 
	return res;
}

int main()
{
	cin>>n>>m;
	
	memset(g,0x3f,sizeof g);
	
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		
		//add(a,b,c);
		g[a][b]=g[b][a]=min(g[a][b],c);
	}//��ͼ 
	//�����ڽ�ͼ��ʱ����Բ������Ի� 
	
	int t=prim();
	
	if(t==INF)puts("impossible");
	else cout<<t<<endl;
	
	return 0;
}
