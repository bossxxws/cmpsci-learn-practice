#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

//把线段数里面的属性定义为最大值

int w[N];//原序列 

int n,m;

struct Node
{
	int l,r;
	int maxv;
}tr[N*4]; 

//建树 
void build(int u,int l,int r)
{
	if(l==r)tr[u]={l,r,w[r]};//如果l==r那就是叶节点，直接赋值 
	else
	{
		//否则的话先赋值，以u为根节点的区间 
		tr[u]={l,r};//等价于 tr[u]={l,r,0};
		int mid=l+r>>1;
		build(u<<1,l,mid),build(u<<1|1,mid+1,r);//u<<1|1就是u*2+1
		tr[u].maxv=max(tr[u<<1].maxv,tr[u<<1|1].maxv);
		
	}
}

int query(int u,int l,int r)
{
	if(tr[u].l>=l && tr[u].r<=r)return tr[u].maxv;
	
	int mid=tr[u].l+tr[u].r>>1;//注意是tr[u].l+tr[u].r而不是l+r>>1，因为当前区间的中点是树里面的中点 ,而不是查询的区间的终点 
	int maxv=INT_MIN;
	if(l<=mid)maxv=max(maxv,query(u<<1,l,r));
	if(r>=mid+1)maxv=max(maxv,query(u<<1|1,l,r));	
	return maxv;
}

int main()
{
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	
	build(1,1,n);
	
	while(m--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int t=query(1,l,r);
		printf("%d\n",t);
	}
	
	return 0;
} 
