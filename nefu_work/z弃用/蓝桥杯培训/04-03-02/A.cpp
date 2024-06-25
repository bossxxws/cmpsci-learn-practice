#include<bits/stdc++.h>

using namespace std;

int c,r;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int ans;


const int N=20+5;

char Map[N][N];
int vis[N][N];
//.�ڴ�ש
// #�״�ש
//@ Ŀǰλ�� 


void dfs(int i,int j)//iΪ������jΪ���� 
{
	Map[i][j]='#';
	ans++;
	for(int k=0;k<4;k++)
	{
		int x=i+dx[k];
		int y=j+dy[k];
		if(x>=1 && x<=r && y>=1 && y<=c && Map[x][y]=='.')
		{
			dfs(x,y);
		}

	}

}

int main()
{
	while(cin>>c>>r)
	{
		if(c==0 && r==0)break;
		
		int idx_i,idx_j;//��¼��ʼλ��
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
			{
				cin>>Map[i][j];
				if(Map[i][j]=='@')
				{
					idx_i=i;
					idx_j=j;
				}
			}
	
		ans=0;
	
		dfs(idx_i,idx_j);
		cout<<ans<<endl;
		
		memset(Map,0,sizeof(Map));
		
	}

						
	return 0;	
}
