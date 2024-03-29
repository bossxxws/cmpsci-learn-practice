#include<bits/stdc++.h>

using namespace std;

const int N=5*1e4+5;

int n,m;

int p[N],d[N];

int find(int x)
{
	if(p[x]!=x)
	{
		int t=find(p[x]);
		d[x]+=d[p[x]];//当前这一级和上一级的距离 
		p[x]=t;
	}
	return p[x];
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)p[i]=i;//初始化自己是一个集合
	int res=0;
	while(m--)
	{
		int t,x,y;
		cin>>t>>x>>y;
		if(x>n || y>n)
		{
			res++;
		}
		else 
		{
			int px=find(x);
			int py=find(y);
			if(t==1)
			{
				if(px==py && (d[x]-d[y])%3!=0)
				{
					res++;
				}
				else if(px!=py)
				{
					p[px]=py;
					d[px]=d[y]-d[x];
					
				}
			}
			else if (t==2)
			{
				if(px==py && (d[x]-d[y]-1)%3!=0)res++;
				else if(px!=py)
				{
					p[px]=py;
					d[px]=d[y]-d[x]+1;
				}
			}
		}
		
	}
	cout<<res<<endl;
	return 0;
}
