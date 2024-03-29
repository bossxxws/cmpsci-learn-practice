//有向无环图一定存在一个拓扑序列
//有向无环图也被成为拓扑图、
//一个无环图，一定至少存在一个入度为0的点
#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;
int n,m;
int h[N],e[N],ne[N],idx;//邻接表的表示方式
int q[N],hh,tt=-1,d[N];//q表示的是队列，d存储的是入度

void add(int a,int b)//a是图的起点，h[a]初始指向-1（因为还没成一条边，只是一个点），后来a指向b，就成了一条边
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;//h[a]最后指向idx
}

bool topsort()
{
    for(int i=1;i<=n;i++)
    {
        if(!d[i])
        {
            q[++tt]=i;
        }
    }
    while(hh<=tt)
    {
        int t =q[hh++];
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            d[j]--;
            if(d[j]==0)
            {
                q[++tt]=j;//如果入度为0则入队
            }
        }
    }
    return tt==n-1;
}

int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
        d[b]++;
    }
    if(topsort())
    {
        for(int i=0;i<n;i++)
        {
            cout<<q[i]<<" ";
        }
    }
    else 
    {
        puts("-1");
    }
    return 0;
}
