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

int f[N][S];//ǰi����Ʒ����ʱ�䲻����j����ȡ���������

bool cmp(node a,node b)
{
    return a.s/a.l <= b.s/b.l;
}

int main()
{
    int t;
    cin>>t;
    int cnt=0;
    while(t--)
    {
        memset(f, -0x3f, sizeof f);//ǡ�õ�������ȫ����ʼ��Ϊ������
        int time=0;
        cin>>n;

        for(int i=1;i<=n;i++)
        {
            int s,e,l;
            cin>>s>>e>>l;
            time+=s;
            a[i]={s,e,l};
        }//�������ݣ������ʱ��time
        
        sort(a+1,a+n,cmp);
		f[0][0]=0;
        //��ʼʹ�ñ���
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=time;j++)
            {
                f[i][j]=f[i-1][j];//��ѡ��i��
                if(j>=a[i].s)f[i][j]=max(f[i][j],f[i-1][j-a[i].s]+max(0,a[i].e-a[i].l*(j-a[i].s)));//���ϵ�����ʧ�������
                //��Ϊ��ǡ�õ���� ����˵j-a[i]���ǳ�ǰ��ʯͷ���ĵ�����
            }
        }
        int res=0;
        
        for(int i=1;i<=time;i++)res=max(f[n][i],res);

        printf("Case #1: %d\n",res);
    }

    return 0;
}

