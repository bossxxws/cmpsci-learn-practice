#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;

#define v first
#define w second

const int M=32001;//容量最大为32000

const int N=63;//最多有N种物品


PII master[N];//存储主件的PII数组

vector<PII>sec[N];//存储附件的数组

//dp
int f[M];

int n,m;
int main()
{
    cin>>m>>n;

    for(int i=1;i<=n;i++)
    {
        int v,p,q;
        cin>>v>>p>>q;
        p*=v;
        if(!q)master[i]={v,p};//是主件的情况
        else sec[q].push_back({v,p});
    }

    //dymanic programming
    for(int i=1;i<=n;i++)
    {
        for(int u=m;u>=0;u--)
        {
            for(int j=0;j<1<<sec[i].size();j++)//附件有几个决定有几种状态
            {

                //附件有n个就有2的n次方种状态
                //j储存了当前附件的选择状态（状态压缩）
                int v=master[i].v;
                int w=master[i].w;
                for(int k=0;k<sec[i].size();k++)//第k个选不选的情况
                {
                    if(j>>k&1)//如果现在这种状态选了第k个
                    {
                        v+=sec[i][k].v;
                        w+=sec[i][k].w;//加上对应的价值
                    }
                }

                if(u>=v)f[u]=max(f[u],f[u-v]+w);
            }
        }
    }
    cout<<f[m]<<endl;
    return 0;
}
