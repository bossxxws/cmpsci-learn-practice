#include<bits/stdc++.h>
using namespace std;
const int N =310;
int dx[8]={1,1,1,0,0,-1,-1,-1},dy[8]={1,0,-1,1,-1,1,0,-1};
int num[N][N],st[N][N];
char g[N][N];    //记录扫雷整张地图
void bfs(int a,int b,int n)   //寻找0点周围的所有点，标记为已遍历
{
    st[a][b]=1;
    num[a][b]=-1;

        for(int i=0;i<8;i++)
        {
            int x=a+dx[i],y=b+dy[i];
            if(x>=0 && x<n && y>=0 && y<n)
            {
                if(!st[x][y] && num[x][y]!=-1)
                {
                    if(num[x][y]>0) st[x][y]=1,num[x][y]=-1;
                    if(num[x][y]==0) bfs(x,y,n);
                }
            }
        }
}
int main()
{
    int T,n;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%s",g[i]);

        memset(num,0,sizeof num);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(g[i][j]!='*')    //不是雷的要统计8个点上雷的总个数
                {
                    for(int k=0;k<8;k++)
                    {
                        int x=i+dx[k],y=j+dy[k];
                        if(x>=0 && x<n && y>=0 && y<n && g[x][y]=='*')
                        {
                            num[i][j]++;
                        }
                    }
                }
                else num[i][j]=-1;   //如果是雷则标记为-1
            }
        }

        memset(st,0,sizeof st);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(num[i][j]==0 && !st[i][j])     //找到一个0点ans++，同时进行bfs
                {
                    ans++;  
                    bfs(i,j,n);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                if(num[i][j]!=-1 && !st[i][j]) ans++;  //找到漏网之鱼，每找到一个就ans++
        }
        printf("Case #%d: %d\n",t,ans);

    }
    return 0;
}

