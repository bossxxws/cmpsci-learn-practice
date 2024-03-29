#include<bits/stdc++.h>

using namespace std;

const int N=101;

typedef pair<int,int> PII;



int n,m;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int g[N][N];
int d[N][N];
int hh,tt;
PII q[N*N];

int bfs()
{
    q[tt]={0,0};
    d[0][0]=0;
    while(hh<=tt)
    {
        auto t=q[hh++];
        int x=t.first;
        int y=t.second;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && d[nx][ny]==-1 &&g[nx][ny]==0)
            {
                d[nx][ny]=d[x][y]+1;
                //cout<<d[nx][ny]<<endl;
                q[++tt]={nx,ny};
            }
        }
    }
    
    return d[n-1][m-1];
    
}

int main()
{
    cin>>n>>m;
    memset(d,-1,sizeof d);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            scanf("%d",&g[i][j]);
        }
    
    cout<<bfs();
    
    return 0;
}
