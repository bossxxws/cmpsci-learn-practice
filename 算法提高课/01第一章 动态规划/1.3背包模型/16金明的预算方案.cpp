#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;

#define v first
#define w second

const int M=32001;//�������Ϊ32000

const int N=63;//�����N����Ʒ


PII master[N];//�洢������PII����

vector<PII>sec[N];//�洢����������

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
        if(!q)master[i]={v,p};//�����������
        else sec[q].push_back({v,p});
    }

    //dymanic programming
    for(int i=1;i<=n;i++)
    {
        for(int u=m;u>=0;u--)
        {
            for(int j=0;j<1<<sec[i].size();j++)//�����м��������м���״̬
            {

                //������n������2��n�η���״̬
                //j�����˵�ǰ������ѡ��״̬��״̬ѹ����
                int v=master[i].v;
                int w=master[i].w;
                for(int k=0;k<sec[i].size();k++)//��k��ѡ��ѡ�����
                {
                    if(j>>k&1)//�����������״̬ѡ�˵�k��
                    {
                        v+=sec[i][k].v;
                        w+=sec[i][k].w;//���϶�Ӧ�ļ�ֵ
                    }
                }

                if(u>=v)f[u]=max(f[u],f[u-v]+w);
            }
        }
    }
    cout<<f[m]<<endl;
    return 0;
}
