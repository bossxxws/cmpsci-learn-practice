//----------spfa�㷨�󸺻�----------
//dist[x] ��ǰ��x��������̾��� 
//cnt[x]  ����
//cnt[x]>=n ��ζ����n���ߣ���ζ����n+1���㣬���Դ���һ���������������һ���Ǹ�Ȩ��
//          ��Ϊֻ�и�Ȩ���������ظ���һ�� 
//Ҳ����cnt[x]>=n��ʾ���ڸ���

#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;

const int N=1e6+10;

int  n,m;

int h[N],e[N],ne[N],idx,w[N];

int dist[N],cnt[N];
bool st[N];

void add(int a,int b,int c)
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}


//�ص����  ------------spfa 
bool spfa()
{
	memset(dist,0x3f,sizeof dist);
	queue<int> q;
	//dist[1]=0;  ��1��ʼ��һ���ܽ�ȥ���������԰����е㶼�Ž�ȥ���ܲ����ҵ�
	for(int i=1;i<=n;i++)
	{
		st[i]=true;
		q.push(i);
	} 
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
				cnt[j]=cnt[t]+1;
				
				
				if(cnt[j]>=n)return true;
				
				
				if(!st[j])
				{
					q.push(j);
					st[j]=true;
				}
			}
		}
	} 
	return false;
	
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
	
	
	if(t)printf("Yes");
	else printf("No");
	
	return 0;
} 
