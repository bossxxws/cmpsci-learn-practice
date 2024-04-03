#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int a[N];
int tr[N];

int n,m;

int lowbit(int x)
{
	return x&-x;
}


int query(int x)
{
    //树状差分数组求和后是某一个位置的变化值（正如差分数组一样），这个值就是区间的变化值
	int res=0;
	for(int i=x;i;i-=lowbit(i))
	//注意是i>0，千万不要写i>=0,因为i最后刚好为0（线段树是从1开始的） 
	//i减去自己的低位1不会小于0，重复减去自己的低位i，最后一定会减到0的 
	{
		res+=tr[i];
	}
	return a[x]+res;
}

void add(int pos,int v)
{
	for(int i=pos;i<=n;i+=lowbit(i))
	{
		tr[i]+=v;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	//cout<<1;
	while(m--)
	{
		char op[2];
		//cout<<1;
		scanf("%s",op);
		//cout<<2;
		if(op[0]=='C')
		{
			//cout<<1;
			int l,r,c;
			cin>>l>>r>>c;
			add(l,c);add(r+1,-c);//树状数组变成树状差分数组 
		}
		else
		{
			//cout<<2;
			int x;
			scanf("%d",&x);
			//cout<<1;
			cout<<query(x)<<endl;
		}
	}
	return 0;
}
