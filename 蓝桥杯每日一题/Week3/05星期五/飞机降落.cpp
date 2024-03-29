#include<bits/stdc++.h>

using namespace std;

const int N=20;

struct plane
{
	int t,d,l;
}p[N]; 

int k,n;
int t[N],d[N],l[N];
bool st[N];

//bool cmp(plane a,plane b)
//{
//	return a.t<b.t;
//}

bool dfs(int cnt,int last)
{
	if(cnt>=n)//飞机达到数量 
	{
		return true;
	}
	for(int i=0;i<n;i++)
	{
		int t=p[i].t;
		int d=p[i].d;
		int l=p[i].l;
		if(!st[i] && t+d>=last)
		{
			st[i]=true;
			if(dfs(cnt+1,max(last,t)+l))return true;
			st[i]=false;
		}
	}
	return false;
}

int main()
{
	cin>>k;
	while(k--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			p[i]={a,b,c};
		}
		memset(st,false,sizeof st);
		if(dfs(0,0))cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;	
} 
