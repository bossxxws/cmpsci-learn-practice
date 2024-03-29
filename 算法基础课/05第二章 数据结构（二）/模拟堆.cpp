#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n,m;

int h[N],ph[N],hp[N],siz;//ph[k]存的是第k个点插入的是什么点，hp[k]堆里面第k个点是第几个插入的点
//即ph是index，hp是插入次序

void heap_swap(int a,int b)
{
    swap(ph[hp[a]],ph[hp[b]]);//交换下标
    swap(hp[a],hp[b]);//对应的次序也换过去
    swap(h[a],h[b]);
}

void down(int u)
{
    int t=u;
    if(u*2<=siz && h[u*2]<h[t])t=u*2;
    if(u*2+1<=siz && h[u*2+1]<h[t])t=u*2+1;
    if(u!=t)
    {
        heap_swap(u,t);
        down(t);
    }
}

void up(int u)
{
    while(u/2 && h[u/2]>h[u])
    {
        heap_swap(u,u/2);
        u/=2;
    }
}


int main()
{ 
    int n,m=0;
    cin>>n;
    while(n--)
    {
        char op[10];
        int k,x;
        cin>>op;
        if(!strcmp(op,"I"))
        {
            cin>>x;
            m++;//次序
            siz++;//下标
            ph[m]=siz;//通过次序找下标
            hp[siz]=m;//通过下标找次序
            h[siz]=x;
            up(siz);
        }
        else if (!strcmp(op,"PM"))cout<<h[1]<<endl;
        else if (!strcmp(op,"DM"))
        {
            heap_swap(1,siz);
            siz--;
            down(1);
        }
        else if(!strcmp(op,"D"))
        {
            cin>>k;
            k=ph[k];//通过次序找出在堆里面的位置（下标）
            heap_swap(k,siz);
            siz--;
            down(k),up(k);
        }
        else
        {
            cin>>k>>x;
            k=ph[k];
            h[k]=x;
            down(k),up(k);
        }
    }
    return 0;
}
