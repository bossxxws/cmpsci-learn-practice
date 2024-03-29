//**********朴素迪杰斯特拉**********
//时间复杂度：0（n**2） 
//适用于单源最短路且所有边权都是正数（最适用于稠密图）


//稠密图用邻接矩阵来存

//稀疏图用邻接表来存
 
 
//1、dist【1】=0（最开始只有一号点的距离是确定的）；dist【i】=正无穷；


//2、for i ：0-n（迭代n次）；                  s集合：当前已确定最短距离的点 

// t <-- 不在s中的，距离当前点最近的点(这个点到起点一定是最短路)

//把t添加到s中

//用t更新其他点的距离（更新方式：看一下从t出去的所有边组成的路径能不能更新其他点的距离）

//比如：1 --> t --> x，看1号点到x的距离能不能用t到x的距离更新

//就是看一下dist【x】是不是大于dist【t】+W（权重） 

//最终确定每一个点到起点的距离 


//无向边相当于连两次边 add（a，b）；add（b，a）； 

#include<bits/stdc++.h>

using namespace std;

const int N=510;

int  n,m;

int g[N][N];

int dist[N];
bool st[N];

int dijkstra()
{
	memset(dist,0x3f,sizeof dist);//把所有距离初始化为正无穷 
	dist[1]=0;//一号点的距离初始化为0 
	
	
	
	for(int i=0;i<n;i++)
	{
		int t=-1;
		
		//不在s中的距离原点最近的点 赋给t
		for(int j=1;j<=n;j++)
		{
			if(!st[j] && (t == -1 || dist[t]>dist[j]))
			{
				t=j; 
			}
		}
		
		st[t]=true;//把t放进s里 ，上面的搜索程序就不会再一次选这个点 
		
		
		//用t更新其他点的距离 
		for(int j=1;j<=n;j++)
		{
			dist[j]=min(dist[j],dist[t]+g[t][j]);
		}
	}
	
	if(dist[n]==0x3f3f3f3f)return -1;//表示没有路可以达到 
	return dist[n]; 
}

int main()
{
	cin>>n>>m;
	
	memset(g,0x3f,sizeof g);//距离设置为正无穷 
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		g[a][b]=min(g[a][b],c); 
	}
	
	int t=dijkstra();
	
	cout<<t<<endl;
	
	return 0;
} 
