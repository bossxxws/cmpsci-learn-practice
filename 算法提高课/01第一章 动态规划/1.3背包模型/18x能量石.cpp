#include<bits/stdc++.h>

using namespace std;

const int N=103;
const int S=10005;

int n;

struct node
{
    int s,e,l;
};

node a[N];

int f[N][S];//前i个物品，总时间不超过j所获取的最大能量

bool cmp(node a,node b)
{
    return a.s/a.l <= b.s/b.l;
}

int main()
{
    int t;
    cin>>t;
    int cnt=0;
    while(t--)
    {
        int time=0;
        cin>>n;

        for(int i=1;i<=n;i++)
        {
            int s,e,l;
            cin>>s>>e>>l;
            time+=s;
            a[i]={s,e,l};
        }//读入数据，算出总时间time

        sort(a+1,a+n,cmp);

        //开始使用背包
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=time;j++)
            {
                f[i][j]=max(f[i][j],f[i-1][j]);
                if(j>=a[i].s)f[i][j]=max(f[i][j],f[i-1][j-a[i].s]+max(0,a[i].e-a[i].l*j));//加上的是流失后的能量
            }
        }
        int res;
        for(int i=1;i<=time;i++)res=max(f[n][i],res);

        printf("Case #1: %d\n",res);
    }

    return 0;
}
