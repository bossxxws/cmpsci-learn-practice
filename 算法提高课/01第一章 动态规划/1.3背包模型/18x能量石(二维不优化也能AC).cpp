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
    return a.s*b.l < b.s*a.l;
}

int main()
{
    int t;
    cin>>t;
    int cnt=0;
    while(t--)
    {
        memset(f, -0x3f, sizeof f);//恰好的条件：全部初始化为负无穷
        int time=0;
        
        cin>>n;

        for(int i=1;i<=n;i++)
        {
            int s,e,l;
            cin>>s>>e>>l;
            time+=s;
            a[i]={s,e,l};
        }//读入数据，算出总时间time
        
        sort(a+1,a+n+1,cmp);//检查半天的原因：这里的a+n+1忘记+1了！！！！！！！！！！
		//真是气死人 
        
        //选前i个，总时间为0的方案数状态都是0 
		//for(int i=1;i<=n;i++)f[i][0]=0;
		f[0][0]=0;
        //开始使用背包
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=time;j++)
            {
                f[i][j]=f[i-1][j];//不选第i个
                if(j>=a[i].s)f[i][j]=max(f[i][j],f[i-1][j-a[i].s]+max(0,a[i].e-a[i].l*(j-a[i].s)));//加上的是流失后的能量
                //因为是恰好的情况 所以说j-a[i]就是吃前面石头消耗的能量
            }
        }
        int res=0;
        
        for(int i=1;i<=time;i++)res=max(f[n][i],res);//前n个物品中选择每种状态中最大的 

        printf("Case #%d: %d\n",++cnt,res);
    }

    return 0;
}

