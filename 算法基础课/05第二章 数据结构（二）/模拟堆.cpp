#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n,m;

int h[N],ph[N],hp[N],siz;//ph[k]����ǵ�k����������ʲô�㣬hp[k]�������k�����ǵڼ�������ĵ�
//��ph��index��hp�ǲ������

void heap_swap(int a,int b)
{
    swap(ph[hp[a]],ph[hp[b]]);//�����±�
    swap(hp[a],hp[b]);//��Ӧ�Ĵ���Ҳ����ȥ
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
            m++;//����
            siz++;//�±�
            ph[m]=siz;//ͨ���������±�
            hp[siz]=m;//ͨ���±��Ҵ���
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
            k=ph[k];//ͨ�������ҳ��ڶ������λ�ã��±꣩
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
