#include<bits/stdc++.h>

using namespace std;

const int N=1e3+3;

#define x first
#define y second

typedef pair<int,int> PII;

PII a[N];

int res[5];

map<PII,bool> m;//记录该位置有没有 

set<PII> s;//记录符合第一条条件的坐标 

int n;

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

int ddx[]={1,-1,1,-1};
int ddy[]={-1,1,1,-1};

int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;//读入垃圾站的坐标 
		
		PII temp=make_pair(a[i].x,a[i].y);
		
		m[temp]=true;
	}
	
	for(int i=1;i<=n;i++)
	{
		int xx=a[i].x;
		int yy=a[i].y;
		
		int cnt1=0;//记录上下左右符合的点的个数 
		for(int j=0;j<4;j++)
		{
			int nx=xx+dx[j];
			int ny=yy+dy[j];
			PII aim=make_pair(nx,ny);
			if(m[aim]==true)cnt1++;
		}
		
		if(cnt1==4)
		{
			s.insert(make_pair(xx,yy));//插入符合第一条条件的坐标 
		}
		
	}
	
	for(auto tt:s)//对每一个坐标进行评分 
	{
		int sc=0;
		int xxx=tt.x;
		int yyy=tt.y;
		for(int i=0;i<4;i++)
		{
			int nxx=xxx+ddx[i];
			int nyy=yyy+ddy[i];
			if(m[make_pair(nxx,nyy)]==true)sc++;
		}
		res[sc]++;
	}
	
	for(int i=0;i<=4;i++)cout<<res[i]<<endl;
	
	return 0;
}
