//bellman-ford 算法 （贝尔曼福特算法）   O(nm)
//for n 次
//    for 所有边 a，b，w
//			dist[b =min(dist[b],dist[a]+w);
//dist[b]<=dist[a]+w;(三角不等式)



#include<bits/stdc++.h> 

using namespace std;

const int N=510,M=1e4+10;

int n,m,k;//n个点m个边，最多经过k条边，求这个条件下的最短路径 
int dist[N],backup[N];//距离 备份 

struct Edge
{
	int a,b,w;//起点 终点 权重 
}edges[M];

int bellman_ford()
{
    memset(dist,0x3f3f3f3f,sizeof dist);
    dist[1]=0;
    for(int i=0;i<k;i++)//迭代k次 
	{
		memcpy(backup,dist,sizeof dist);//每次迭代前备份一次，防止串联(保证每次走相同的步数)
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
