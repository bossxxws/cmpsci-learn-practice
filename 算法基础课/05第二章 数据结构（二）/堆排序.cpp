//����һ����ȫ���������������һ���ڲ��ڵ������ڵ㣨���������������ģ� 
//С���ѣ�
//ÿ���㶼С�ڵ������Ҷ��ӣ����ڵ����������ݽṹ����Сֵ��
//����ѣ�
//ͬ��
//�����дһ���ѣ�
/*
1.����һ����
heap[++size]=x;
up[size];
2.�󼯺ϵ�����С��ֵ
heap[1];
3.ɾ����Сֵ
heap[1]=heap[size];size--;
down[1];
3.ɾ������һ��Ԫ��
heap[k]=heap[size];size--;(���)down[k]  or  (��С)up[k];
4.�޸�����һ��Ԫ�� 
heap[k]=x;(���)down[k]  or  (��С)up[k];
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

void up��int u)
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
