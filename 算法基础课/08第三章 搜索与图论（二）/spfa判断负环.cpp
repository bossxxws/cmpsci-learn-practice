//----------spfa算法求负环----------
//dist[x] 当前点x到起点的最短距离 
//cnt[x]  边数
//cnt[x]>=n 意味着有n条边，意味着有n+1个点，所以存在一个环，并且这个环一定是负权的
//          因为只有负权才能令其重复走一遍 
//也就是cnt[x]>=n表示存在负环

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


//重点代码  ------------spfa 
bool spfa()
{
	memset(dist,0x3f,sizeof dist);
	queue<int> q;
	//dist[1]=0;  从1开始不一定能进去负环，所以把所有点都放进去看能不能找到
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
		for(int i=h[t];i!=-1;i=ne[i])//更新一下t的所有邻边 
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
