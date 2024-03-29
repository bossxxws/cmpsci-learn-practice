#include<bits/stdc++.h>

using namespace std;

int k,n;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

const int N=103;

char g[N][N];

bool f; 

void dfs(int x1,int y1,int aimx,int aimy)
{
	if(x1==aimx && y1==aimy)
	{
		//cout<<y1<<" "<<aimy<<endl;
	    f=true;
	    return ;
	}
	g[x1][y1]='#';
	for(int i=0;i<4;i++)
	{
		int nx=dx[i]+x1;
		int ny=dy[i]+y1;
		if(nx>=1 && nx <= n && ny>=1 && ny<=n && g[nx][ny]=='.')
		{
			//cout<<nx<<" "<<ny<<endl;
			//cout<<g[nx][ny]<<endl;
			dfs(nx,ny,aimx,aimy);
		}
	}
} 

int main()
{
	cin>>k;
	while(k--)
	{
		//cout<<"intput n";
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				//cout<<"reading"<<endl;
				cin>>g[i][j];	
			} 
			//cout<<g[1][4];
		//cout<<"yeah";
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		x1++,y1++,x2++,y2++;//因为我的坐标是从1开始计的 
		f=false;
		//cout<<"readover";
		//cout<<x1<<" "<<y1<<endl;
		if(g[x1][y1]!='#')dfs(x1,y1,x2,y2);
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

	return 0;
}
