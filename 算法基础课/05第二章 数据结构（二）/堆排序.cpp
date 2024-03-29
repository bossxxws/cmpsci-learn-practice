//堆是一个完全二叉树（除了最后一层内部节点其他节点（包括根）都是满的） 
//小根堆：
//每个点都小于等于左右儿子（根节点是整个数据结构的最小值）
//大根堆：
//同理
//如何手写一个堆？
/*
1.插入一个数
heap[++size]=x;
up[size];
2.求集合当中最小的值
heap[1];
3.删除最小值
heap[1]=heap[size];size--;
down[1];
3.删除任意一个元素
heap[k]=heap[size];size--;(变大)down[k]  or  (变小)up[k];
4.修改任意一个元素 
heap[k]=x;(变大)down[k]  or  (变小)up[k];
*/ 

#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n,m;

int h[N],siz;

void down(int u)
{
    int t=u;
    if(u*2<=siz && h[u*2]<h[t])t=u*2;
    if(u*2+1<=siz && h[u*2+1]<h[t])t=u*2+1;
    if(u!=t)
    {
        swap(h[u],h[t]);
        down(t);
    }
}

void up（int u)
{
    while(u/2 && h[u/2]>h[u])
    {
        swap(h[u],h[u/2]);
        u/=2;
    }
}

int main()
{ 
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>h[i];
    siz=n;
    
    for(int i=n/2;i;i--)down(i);
    
    while(m--)
    {
        cout<<h[1]<<" ";
        h[1]=h[siz];
        siz--;
        down(1);
    }
    return 0;
}
