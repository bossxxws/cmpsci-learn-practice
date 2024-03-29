//spfa算法（一般O（m），最坏O（nm））：                       
//用bfs对贝尔曼福特算法进行优化 

/*
for 所有边 a，b，w
dist[b]=min(dist[b],dist[a]+w)   ----- 对这个进行优化


步骤： 
queue  <-----  1
while queue 不空
1.	t  <----- q.front()
			  q.pop()
2.
	更新t的所有出边  t----->b(w)
	queue <------ b

核心思想：一个点更新过，再拿他更新别人 

 


*/ 

//优先用spfa算法，这个算法最常用适用性最强，如果被卡再换其他方法（一般O（m），最坏O（nm）） 
//一般情况下spfa算法比迪杰斯特拉算法快一些
//如果被卡了，就换堆优化版的迪杰斯特拉算法 （  时间复杂度O（mlogn）  ） 
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


//重点代码  ------------spfa 
int spfa()
{
	memset(dist,0x3f,sizeof dist);
	dist[1]=0;
	queue<int> q;
	q.push(1);
	st[1]=true;//防止队列中存储重复的点;
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
