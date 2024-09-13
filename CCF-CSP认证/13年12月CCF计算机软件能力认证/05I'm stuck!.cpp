#include<bits/stdc++.h> 

using namespace std;

const int N=53;

int r,c,cnt;

char g[N][N];

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int mark[N][N];

struct id
{
	int x;
	int y;
};

id target;
id start;

bool sts[N][N],stt[N][N];

void dfss(int x,int y)
{

	
	if(g[x][y]=='#' || mark[x][y])
	{
		return ;
	}
	
	mark[x][y]=1;
		
	if(g[x][y]=='S')
	{
		//cout<<'S'<<endl;
		sts[x][y]=1;
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(!mark[nx][ny] && nx>0 && ny>0 && nx<=r && ny<=c && g[nx][ny]!='#')dfss(nx,ny);
		}
		
	}
	else if(g[x][y]=='+')
	{
	    //cout<<'+'<<endl;
	    sts[x][y]=1;
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(!mark[nx][ny] && nx>0 && ny>0 && nx<=r && ny<=c && g[nx][ny]!='#')dfss(nx,ny);
		}
	}
	else if(g[x][y]=='-')
	{
	    //cout<<'-'<<endl;
	    sts[x][y]=1;
		for(int i=0;i<2;i++)
		{
			int nx=x;
			int ny=y+dx[i];
			if(!mark[nx][ny] && nx>0 && ny>0 && nx<=r && ny<=c && g[nx][ny]!='#')dfss(nx,ny);
		}
	}
	else if(g[x][y]=='|')
	{
	    //cout<<'|'<<endl;
	    sts[x][y]=1;
		for(int i=2;i<4;i++)
		{
			int nx=x+dy[i];
			int ny=y;
			if(!mark[nx][ny] && nx>0 && ny>0 && nx<=r && ny<=c && g[nx][ny]!='#')dfss(nx,ny);
		}
	}
	else if(g[x][y]=='.')
	{
        //cout<<'.'<<endl;
        sts[x][y]=1;
		int nx=x+1;
		int ny=y;
		if(!mark[nx][ny] && nx>0 && ny>0 && nx<=r && ny<=c && g[nx][ny]!='#')dfss(nx,ny);
		
	}
	else if(g[x][y]=='T')
	{
		//cout<<'T'<<endl;
		sts[x][y]=1;
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(!mark[nx][ny] && nx>0 && ny>0 && nx<=r && ny<=c && g[nx][ny]!='#')dfss(nx,ny);
		}
	}
}

bool dfs1(int x,int y)
{

	
	if(g[x][y]=='#' || mark[x][y])
	{
		return false;
	}
	
	mark[x][y]=1;
		
	if(g[x][y]=='S')
	{
		//cout<<'S'<<endl;
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i]; 
			int ny=y+dy[i];
			if(!mark[nx][ny] && nx>0 && ny>0 && nx<=r && ny<=c && g[nx][ny]!='#')if(dfs1(nx,ny))return true;
		}
		
	}
	else if(g[x][y]=='+')
	{
	    //cout<<'+'<<endl;
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(!mark[nx][ny] && nx>0 && ny>0 && nx<=r && ny<=c && g[nx][ny]!='#')if(dfs1(nx,ny))return true;
		}
	}
	else if(g[x][y]=='-')
	{
	    //cout<<'-'<<endl;
		for(int i=0;i<2;i++)
		{
			int nx=x;
			int ny=y+dx[i];
			if(!mark[nx][ny] && nx>0 && ny>0 && nx<=r && ny<=c && g[nx][ny]!='#')if(dfs1(nx,ny))return true;
		}
	}
	else if(g[x][y]=='|')
	{
	    //cout<<'|'<<endl;
		for(int i=2;i<4;i++)
		{
			int nx=x+dy[i];
			int ny=y;
			if(!mark[nx][ny] && nx>0 && ny>0 && nx<=r && ny<=c && g[nx][ny]!='#')if(dfs1(nx,ny))return true;
		}
	}
	else if(g[x][y]=='.')
	{
        //cout<<'.'<<endl;
		int nx=x+1;
		int ny=y;
		if(!mark[nx][ny] && nx>0 && ny>0 && nx<=r && ny<=c && g[nx][ny]!='#')if(dfs1(nx,ny))return true;
		
	}
	else if(g[x][y]=='T')
	{
	    return true;
		//cout<<'T'<<endl;
// 		for(int i=0;i<4;i++)
// 		{
// 			int nx=x+dx[i];
// 			int ny=y+dy[i];
// 			if(!mark[nx][ny] && nx>0 && ny>0 && nx<=r && ny<=c && g[nx][ny]!='#')dfs1(nx,ny);
// 		}
	}
	return false;
}

int main()
{
	scanf("%d%d",&r,&c);
	
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			cin>>g[i][j];
			if(g[i][j]=='T')target.x=i,target.y=j;
			if(g[i][j]=='S')start.x=i,start.y=j;
		//	cout<<start.x<<" "<<start.y<<endl;
		}
	}
	
	if(dfs1(start.x,start.y))stt[start.x][start.y]=1;
// 	cout<<st[1]<<endl;
	if(!stt[start.x][start.y])
	{
	    printf("I'm stuck!");
	    return 0;
	}
//cout<<r<<" "<<c<<endl;
// 	for(int i=1;i<=r;i++)
// 	{
// 	    for(int j=1;j<=c;j++)
// 	    {
// 	        cout<<g[i][j];
// 	    }
// 	    cout<<endl;
// 	}
//	
    //cout<<"----------------------------------------"<<endl;
	for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            mark[i][j]=0;
        }
    }//清空状态数组
    dfss(start.x,start.y);
    //cout<<"----------------------------------------"<<endl;
    
    memset(mark,0,sizeof mark);//清空状态数组
		    
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
		    for(int i=1;i<=r;i++)
		    {
		        for(int j=1;j<=c;j++)
		        {
		            mark[i][j]=0;
		        }
		    }//清空状态数组
		    if(dfs1(i,j))stt[i][j]=1;
		    //cout<<"i,j: "<<i<<" "<<j<<" st0: "<<sts[i][j]<<" st1: "<<stt[i][j]<<endl;
			if(sts[i][j] && !stt[i][j])cnt++;
		}
	}
	
	printf("%d",cnt);
	
	
	return 0;
}
