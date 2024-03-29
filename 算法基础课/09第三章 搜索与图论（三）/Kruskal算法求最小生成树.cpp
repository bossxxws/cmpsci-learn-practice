//最小生成树 
//克鲁斯卡尔算法 Kruskal  
//时间复杂度： O（mlogm）
//---------稀疏图--------- 

//1.将所有边按权重从小到大排序   

//2. 枚举每条边：a-b 权重是c
//如果a，b不连通，将这条边加入到集合中 

#include<bits/stdc++.h>

using namespace std;

const int N=200000+10;

int n,m;

int p[N];//并查集 


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
		p[i]=i;//一开始并查集中的每个点都不是连通的
	}
	
	int res=0,cnt=0;
	
	for(int i=0;i<m;i++)
	{
		int a=edges[i].a,b=edges[i].b,w=edges[i].w;
		a=find(a);
		b=find(b);
		if(a!=b)
		{
			
			p[a]=b;//并查集中的合并操作，相当于加入到最小生成树的一部分（最开始每个部分不一定连接）
			//最后会成为一个最小生成树，成为一部分
			//如果没有成为一部分则不是最小生成树
			
			res+=w;//最小生成树的权 
			cnt++;//存入边的数目 
			
		}
	}
	
	if(cnt<n-1)puts("impossible");//没有成为一部分（加入的点小于n-1）
	else cout<<res<<endl;
	
}
