#include<bits/stdc++.h>

using namespace std;

//01���������󷽰���
//f[i]�洢���Ϊi��ʱ�����߼�ֵ
//cnt[i]�洢���Ϊi��ʱ�����߼�ֵ(f[i])��Ӧ�ķ�����

const int N=1003;

int f[N];
int cnt[N];

int v[N],w[N];

int mod=1e9+7;

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 0; i <= m; i ++)  cnt[i] = 1;//��ʼֵȫ������Ϊ1
    //��Ϊ��߼�ֵ������Ϊ0�������Ϳ�����һ��
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&v[i],&w[i]);
    }

    for(int i=1;i<=n;i++)
    for(int j=m;j>=v[i];j--)
        {
            int value=f[j-v[i]]+w[i];
            if(value>f[j])//�ҵ���ֵ���ߵķ���
            {
                f[j]=value;
                cnt[j]=cnt[j-v[i]];
            }
            else if(value==f[j])
            {
                cnt[j]=(cnt[j]+cnt[j-v[i]])%mod;
            }
        }
    cout<<cnt[m];
    return 0;
}

