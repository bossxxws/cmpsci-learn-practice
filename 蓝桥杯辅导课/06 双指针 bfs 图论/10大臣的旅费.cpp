#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

typedef long long LL;

int h[2*N],e[2*N],ne[2*N],w[2*N],idx;//w储存的是边权 

int maxu,maxd=-1;

int n;
//由于从首都到任意一个大城市的路都是唯一的
//所以这是一棵树 
//最长的路就是数的直径
//找树的直径：
//先找距离某一点最远的点
//再找这个最远的点 的 最远的点 

int add(int a,int b,int l)
{
	
	e[idx]=b;//e存储idx对应的节点号 
	w[idx]=l;//w储存idx对应的边权 
	ne[idx]=h[a];
	h[a]=idx++;
	
}

void dfs(int son,int father,int d)
{
	for(int i=h[son];i!=-1;i=ne[i])
	{
		int j=e[i];
		int k=w[i];//取出节点号和对应的权重
		if(j==father)continue;
		if(maxd<k+d)
		{
			maxd=k+d;
			maxu=j;	
		} 
		dfs(j,son,d+k);//j是son的子节点，这里倒反天罡 （为了更新最大距离） 
	}
}


int main()
{
	cin>>n;
	memset(h,-1,sizeof h);
	for(int i=1;i<=n-1;i++)
	{
		int a,b,l;
		
		scanf("%d%d%d",&a,&b,&l);
		
		add(a,b,l);
		
		add(b,a,l);
		
	}
	
	dfs(1,-1,0);//找不存在的父节点（找距离1节点最远的节点） 
	dfs(maxu,-1,0);//maxu定时距离1最远的节点 
	//通过maxu更新最远距离 
	LL sum=((LL)(1+10)+(maxd+10))*maxd/2;
	cout<<sum;
	return 0;
}
