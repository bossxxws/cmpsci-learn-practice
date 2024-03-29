/*
状态压缩N的极限是20

所以说N比较小的时候可以考虑状态压缩
 
状态表示：
	集合：
			f[u][0]表示从以u为根的子树选择，且不选择u这个点的方案
			f[u][1]表示从以u为根的子树选择，且选择u这个点的方案 
	属性：  MAX 

状态计算：
			f[u][0]是其 每个子树根节点所有状态中的最大值 相加
			f[u][1]是其 每个子树根节点的值相加（因为不能选上司，所以只有一个状态） 
			递归到u这个点的时候，先递归处理他的儿子，先把儿子处理好 

*/
#include<bits/stdc++.h>

using namespace std;

const int N=6010;

int n;

int happy[N]; 

int h[N],e[N],ne[N],idx;//邻接表存储

int f[N][2]; 

bool has_father[N];

void add(int a,int b)
{
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
} 

void dfs(int u)
{
	f[u][1]=happy[u];
	
	for(int i=h[u];i!=-1;i=ne[i])
	{
		int j=e[i];
		
		dfs(j);//先把儿子算一下
		
		f[u][0]+=max(f[j][0],f[j][1]);
		
		f[u][1]+=f[j][0]; 
	}
} 

int main()
{
	scanf("%d",&n);
	
	memset(h,-1,sizeof h); 
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&happy[i]);
	}
	
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		//b是a的上司
		has_father[a]=true; 
		add(b,a);
	}
	
	int root=1;
	
	while(has_father[root])root++;//一直到根结点 
	
	dfs(root);
	
	printf("%d",max(f[root][0],f[root][1]));
	//根节点上的两种状态：取根节点，不取根节点
		
	return 0;
}
