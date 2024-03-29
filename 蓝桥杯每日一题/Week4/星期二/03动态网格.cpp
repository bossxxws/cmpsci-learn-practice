#include<bits/stdc++.h>

using namespace std;

const int N=1001;

int g[N][N];
int st[N][N];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int t;
int n,m;
int q;


void bfs(int x,int y)
{
	st[x][y]=1;
	
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=0 && ny>=0 && nx<n && ny<m && !st[nx][ny] && g[nx][ny]==1)
		{
			bfs(nx,ny);
		}
	}
	
}



int main()
{
	cin>>t;
	int cnt=1;
	while(t--)
	{
		cin>>n>>m;

		for(int i=0;i<n;i++)
		{
			string s;
			cin>>s;
			//cout<<s<<endl;
			for(int j=0;j<m;j++)
			{			
				g[i][j]=s[j]-'0';
				//cout<<s;
			}
		}
		/*
		for(int i=0;i<n;i++)
		{
            
			for(int j=0;j<m;j++)
			{			
				cout<<g[i][j];

			}
			cout<<endl;
		}
		*/
			//cout<<"read";
		cin>>q;

		cout<<"Case #"<<cnt<<":"<<endl;
        cnt++;
		while(q--)
		{
			char op;
			cin>>op;
			if(op=='Q')
			{
			    //printf("Case #%d:",&cnt);
			    memset(st,0,sizeof st);
				int res=0;
				for(int i=0;i<n;i++)
					for(int j=0;j<m;j++)
					{
						if(g[i][j]==1 && !st[i][j])
						{
						    //cout<<"ko"<<endl;
							bfs(i,j);
							res++;
						}
					}
				cout<<res<<endl;
			}
			else
			{
				int x,y,v;
				cin>>x>>y>>v;
				g[x][y]=v;
			}
		}
	}
	return 0;
}
