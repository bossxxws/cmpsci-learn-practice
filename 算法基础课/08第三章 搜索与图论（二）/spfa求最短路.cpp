//spfa�㷨��һ��O��m�����O��nm������                       
//��bfs�Ա����������㷨�����Ż� 

/*
for ���б� a��b��w
dist[b]=min(dist[b],dist[a]+w)   ----- ����������Ż�


���裺 
queue  <-----  1
while queue ����
1.	t  <----- q.front()
			  q.pop()
2.
	����t�����г���  t----->b(w)
	queue <------ b

����˼�룺һ������¹������������±��� 

 


*/ 

//������spfa�㷨������㷨�����������ǿ����������ٻ�����������һ��O��m�����O��nm���� 
//һ�������spfa�㷨�ȵϽ�˹�����㷨��һЩ
//��������ˣ��ͻ����Ż���ĵϽ�˹�����㷨 ��  ʱ�临�Ӷ�O��mlogn��  �� 
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;

const int N=1e6+10;

int  n,m;

int h[N],e[N],ne[N],idx,w[N];

int dist[N];
bool st[N];

void add(int a,int b,int c)
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}


//�ص����  ------------spfa 
int spfa()
{
	memset(dist,0x3f,sizeof dist);
	dist[1]=0;
	queue<int> q;
	q.push(1);
	st[1]=true;//��ֹ�����д洢�ظ��ĵ�;
	while(q.size())
	{
		int t=q.front();
		q.pop();
		st[t]=false;
		for(int i=h[t];i!=-1;i=ne[i])//����һ��t�������ڱ� 
		{
			int j=e[i];
			if(dist[j]>dist[t]+w[i])
			{
				dist[j]=dist[t]+w[i];
				if(!st[j])
				{
					q.push(j);
					st[j]=true;
				}
			}
		}
	} 
	if(dist[n]==0x3f3f3f3f)return 0x3f3f3f3f;
	else return dist[n];
	
}

int main()
{
	scanf("%d%d",&n,&m);
	
	memset(h,-1,sizeof h);
	
	while(m--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
	}
	
	int t=spfa();
	
	
	if(t==0x3f3f3f3f)printf("impossible");
	else printf("%d\n",t);
	
	return 0;
} 
