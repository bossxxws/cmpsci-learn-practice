//树状数组中所有的奇数都和原数组相等 

#include<bits/stdc++.h>

using namespace std;

const int Max=1e6+10;

const int N=1e6+10;

int tree[Max];

//树状数组可以解决： 
//某个位置上的数，加上一个数---单点修改
//求某一个前缀和---区间查询 

//+差分=区间修改 单点查询 || 区间修改 区间查询 

//前缀和数组不支持修改，只支持查询 
//lowbit（x）=2**k（k为末尾连续0的个数） 

// 树状数组每个位置存的都是原数组一段数的和(从x-lowbit(x)到x)
//c[x]=value[x-lowbit(x) ,x]     

//树状数组的三个操作 
int lowbit(int x)
{
	return x&-x;
}

int query(int x)
{
	int res=0;
	for(int i=x;i;i-=lowbit(i))
	{
		res+=tree[i];
	}
	return res;
}

int add(int x,int v)//在某一个位置x加上v （会影响到后面的树根，所以有如下写法） 
{
	for(int i=x;i<=Max;i+=lowbit(i))
	{
		tree[i]+=v;
	}
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++)
	{
		int v;
		scanf("%d",&v);
		add(i,v);
	}

	while(m--)
	{
		int op,a,b;
		scanf("%d%d%d",&op,&a,&b);
		
		if(op==0)
		{
			int res=query(b)-query(a-1);
			printf("%d\n",res);
		}
		else
		{
			add(a,b);
		}
	}
	return 0;
} 
