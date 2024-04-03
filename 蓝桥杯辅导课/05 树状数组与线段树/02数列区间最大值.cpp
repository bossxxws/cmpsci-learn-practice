#include<bits/stdc++.h>
//求的是最大的数而不是的区间和！！！！！！
//故而树状数组不好做，要用线段树
using namespace std;

int n,m;

const int N=1e6+10;

int tr[N];

//三个函数
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

int add(int x,int v)
{
	for(int i=x;i<=N;i+=lowbit(i))
	{
		tr[i]+=v;
	}
}

int main()
{
	cin>>n>>m;

	for(int i=1;i<=n;i++)//加入到tr数组
	{
		int t;
		scanf("%d",&t);
		add(i,t);
	}
	
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		//cout<<a<<" "<<b<<endl;
		int res=query(b)-query(a-1);
		printf("%d\n",res);
	} 
	
	return 0;
}
