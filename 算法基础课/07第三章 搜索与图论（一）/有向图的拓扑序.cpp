//�����޻�ͼһ������һ����������
//�����޻�ͼҲ����Ϊ����ͼ��
//һ���޻�ͼ��һ�����ٴ���һ�����Ϊ0�ĵ�
#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;
int n,m;
int h[N],e[N],ne[N],idx;//�ڽӱ�ı�ʾ��ʽ
int q[N],hh,tt=-1,d[N];//q��ʾ���Ƕ��У�d�洢�������

void add(int a,int b)//a��ͼ����㣬h[a]��ʼָ��-1����Ϊ��û��һ���ߣ�ֻ��һ���㣩������aָ��b���ͳ���һ����
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;//h[a]���ָ��idx
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
                q[++tt]=j;//������Ϊ0�����
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
