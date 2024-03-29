#include<bits/stdc++.h>

using namespace std;

const int N=53;

char g[N][N];
int st[N][N];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

int n,m;
int cnt=0;
typedef pair<int,int> PII;

vector<PII> area[2];

#define x first
#define y second

/* 6 16
................
..XXXX....XXX...
...XXXX....XX...
.XXXX......XXX..
........XXXXX...
.........XXX....
*/

//3

//把每个x的位置记下来，然后进行计算 
void dfs(int x,int y)
{
	st[x][y]=1;
	area[cnt].push_back({x,y});
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(!st[nx][ny] && nx>=1 && nx <=n && ny>=1 && ny<=m && g[nx][ny]=='X')
		{
			dfs(nx,ny);
		}
		//cout<<"yes"; 
	}
} 

int main()
{

	cin>>n>>m;
	//读入数据 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)cin>>g[i][j];
	//cout<<"res";
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(!st[i][j] && g[i][j]=='X')
			{
				dfs(i,j);
				cnt++;
			}
			//cout<<g[i][j];
		}
	
	int res=3000;
	for(auto a : area[0])
		for(auto b :area[1])
		{
			//cout<<a.x<<" "<<b.x<<" "<<endl;
			//cout<<a.y<<" "<<b.y<<" "<<endl;
			res=min(res,abs(a.x-b.x)+abs(a.y-b.y));
		}
	cout<<res-1;
			
	return 0;	
} 
