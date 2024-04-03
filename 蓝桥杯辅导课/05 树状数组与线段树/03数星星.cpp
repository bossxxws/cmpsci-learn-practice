#include<bits/stdc++.h>

//插入星星，如果该位置上有星星则表示为1，所以<=x的星星的数量可以表示为前缀和 
//两个操作：插入和询问，并且可以转化为区间和，所以想到树状数组 
//注意是按x、y增序插入的（每次插入都在原始星空的右上方），所以说可以挨个求星星的等级 
using namespace std;

const int N=15000+10,M=32000+10;

int n;
 
int tr[M];

int level[N];

int lowbit(int x)
{
	return x&-x;
}

int query(int x)
{
	int res=0;
	for(int i=x;i;i-=lowbit(i))
	{
		res+=tr[i];
	}
	return res;
}

void add(int x,int v)
{
	for(int i=x;i<=M;i+=lowbit(i))
	{
		tr[i]+=v;
	}
}

int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x++;//树状数组是从1开始的 
		int t=query(x);
		level[t]++;
		add(x,1);
	}
	
	for(int i=0;i<n;i++)
	{
		printf("%d\n",level[i]);
	}	
	return 0;
}
