//最小生成树 
//朴素版Prim算法 朴素版普利姆算法
//     时间复杂度：O(n**2) 
//---------稠密图常用---------
//邻接矩阵 

//找到不在集合中的（集合是确定最小距离的点）最小编号的点 
//不在集合中就是不确定最短距离的点 



/*
初始化dist【i】=正无穷 
for（i=0；i<n;i++） 
{
	1.找到集合外距离最近的点，赋给t
	2.用t来更新其他点到--集合--（迪杰斯特拉是到起点的距离）的距离 
	3.把t加到st里（st【t】=true） 
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
	//n次迭代
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
		

		st[t]=true;//把这个点加到树里面，成为树的一部分 
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
	}//建图 
	//可以在建图的时候忽略不读入自环 
	
	int t=prim();
	
	if(t==INF)puts("impossible");
	else cout<<t<<endl;
	
	return 0;
}
