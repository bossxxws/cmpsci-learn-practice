#include<bits/stdc++.h>
using namespace std;
const int N =310;
int dx[8]={1,1,1,0,0,-1,-1,-1},dy[8]={1,0,-1,1,-1,1,0,-1};
int num[N][N],st[N][N];
char g[N][N];    //��¼ɨ�����ŵ�ͼ
void bfs(int a,int b,int n)   //Ѱ��0����Χ�����е㣬���Ϊ�ѱ���
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
                if(g[i][j]!='*')    //�����׵�Ҫͳ��8�������׵��ܸ���
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
                else num[i][j]=-1;   //�����������Ϊ-1
            }
        }

        memset(st,0,sizeof st);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(num[i][j]==0 && !st[i][j])     //�ҵ�һ��0��ans++��ͬʱ����bfs
                {
                    ans++;  
                    bfs(i,j,n);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                if(num[i][j]!=-1 && !st[i][j]) ans++;  //�ҵ�©��֮�㣬ÿ�ҵ�һ����ans++
        }
        printf("Case #%d: %d\n",t,ans);

    }
    return 0;
}

