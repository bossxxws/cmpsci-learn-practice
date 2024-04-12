#include<bits/stdc++.h>

using namespace std;

int k,n; 

const int N=11;

bool st[N];

struct plane
{
	int t,d,l;
}p[N];

//u已经降落的飞机数量 
//l为上一架飞机的降落时间  
bool dfs(int u,int last)
{
	if(u>=n)//如果飞机数量达到就输出YES
	{
		//cout<<"YES"<<endl;
		return true;
	}
	
	for(int i=0;i<n;i++)
	{
		if(!st[i])
		{
			st[i]=true;//标记从此开始搜索 
			//这一家飞机可以降落的时间加上降落的时间 
			//上一架飞机降落完的时间加上立即降落的时间 
			//这两个值取最大值 
			if(p[i].t+p[i].d>=last)if(dfs(u+1,max(p[i].l+p[i].t,last+p[i].l)))return true;
			st[i]=false;//回溯 	
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
		memset(st,false,sizeof st);
		for(int i=0;i<n;i++)
		{
			int t,d,l;
			scanf("%d%d%d",&t,&d,&l);
			p[i].t=t;
			p[i].d=d;
			p[i].l=l;
		}
		
		bool t=dfs(0,0);
		if(t)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;	
} 
