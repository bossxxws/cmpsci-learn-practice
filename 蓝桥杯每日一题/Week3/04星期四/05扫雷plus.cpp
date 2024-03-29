#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int X=1e9+1;

int n,m,res=0;

const int MAXMAX=-1;

const int N=999997,M=999997;

LL h[N];//哈希数组

int hn[N],hr[N];//炸弹数量和最大半径

int st[N];

LL get_hash_number(int x,int y)
{
	return (LL)x*X + y;	
} 

int find(int x,int y)
{
	LL t=get_hash_number(x,y);
	int key=(t%M+M)%M;
	//cout<<key;
	while(h[key]!=MAXMAX && h[key]!=t)
	{
		key++;
		if(key==M)key=0;
	}
	//cout<<key<<endl;
	return key;
}

bool check(int x,int y,int x1,int y1,int r)
{
	int d=(x-x1)*(x-x1)+(y-y1)*(y-y1);
	return d<=r*r;
}

void dfs(int x,int y,int r)
{
	for(int i=-r;i<=r;i++)
		for(int j=-r;j<=r;j++)
		{
			int nx=x+i;
			int ny=y+j;
			int t=find(nx,ny);
			//if(nx==4 && ny==4)cout<<hn[find(4,4)]<<endl;
			//cout<<t;
			//cout<<nx<<" "<<ny<<endl;
			if(!st[t] && hn[t] && check(x,y,nx,ny,r))
			{
				//cout<<"yes";
				//cout<<t;
				st[t]=1;	
				res+=hn[t];
				int nr=hr[t];
				//cout<<hr[t];
				//cout<<nx<<" "<<ny;
				//cout<<hn[find(nx,ny)];
				//cout<<"dfs"<<endl;
				dfs(nx,ny,nr);// 2 2 4---->4 4 2
			}
		}

}

int main()
{
	memset(h,-1,sizeof h);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		int x,y,r;
		scanf("%d%d%d",&x,&y,&r);
		int key=find(x,y);
		LL t=get_hash_number(x,y);
		h[key]=t;//维护哈希表 
		hn[key]++;
		hr[key]=max(hr[key],r);
	}
	
	for(int i=0;i<m;i++)
	{
		int xx,yy,rr;
		scanf("%d%d%d",&xx,&yy,&rr);
		dfs(xx,yy,rr);
	}
	cout<<res<<endl;
	//cout<<hn[find(4,4)]<<endl;
	//cout<<hn[find(2,2)]<<endl;
	return 0;
}

/*
2 1
2 2 4
4 4 2
0 0 5

2
*/
