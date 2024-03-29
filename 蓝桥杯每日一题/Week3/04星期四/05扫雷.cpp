#include<bits/stdc++.h>

using namespace std;

const int N=999997,M=999997,X=1e9+1;

const int maxmax=-1;

int n,m;

typedef long long LL;

LL h[M];//哈希数组 (只是利用一下进行编号)

bool st[N];//判断是否访问过 

struct ids
{
	int snumber=0;
	int sr=-1;	
};

ids id[M];
int res=0;//id存储某个位置上的信息 :有几个地雷，最大半径是多少 
 
LL get_hash_number(int x,int y)
{
	return (LL)x*X+y;
}//为了能转化为独一无二能放下的的编号 （因为x和y相加会爆int），必须用特殊方法转化哈希
//将两个坐标的地址信息转化为一个数的地址信息为其选址 

int find(int x,int y)
{
	LL t=get_hash_number(x,y);//得到特殊编号 
	int key=(t%M+M)%M;//转化为独一无二能放下的的编号 
	if(h[key]!=maxmax && h[key]!=t)
	{
		key++;
		if(key==M)key=0;
	}
	return key;
}

bool check(int x1,int y1,int x2,int y2,int r)
{
	int d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);	
	return d<=r*r;
} 

/*
void insert(int x,int y)
{
	int key=find(x,y);
	h[key]=get_hash_number(x,y);
}
*/

void dfs(int x,int y,int r)
{
	//cout<<"yes";
	for(int i=-r;i<=r;i++)
		for(int j=-r;j<=r;j++)
		{
			int nx=x+i;
			int ny=y+j;
			int t=find(nx,ny);
			//cout<<nx<<" "<<ny<<endl;
			if(!st[t] && id[t].snumber && check(x,y,nx,ny,r))//(x,y)为爆炸圆心坐标 
			{
				res+=id[t].snumber;
				int nr=id[t].sr;
				st[t]=1;
				//cout<<nx<<" "<<ny<<endl;
				//cout<<nr;
				dfs(nx,ny,nr);//nx,ny坐标的地雷爆炸，爆炸半径是nr 
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
		LL t =get_hash_number(x,y);
		int key=find(x,y);
		h[key]=t;
		id[key].snumber++;
		id[key].sr=max(id[key].sr,r);
	}
	
	//枚举导弹
	for(int i=0;i<m;i++)
	{
		int xx,yy,rr;
		scanf("%d%d%d",&xx,&yy,&rr);
		dfs(xx,yy,rr);
	}
	
	cout<<res;
	return 0;	
} 
/*
2 1
2 2 4
4 4 2
0 0 5

2
*/
