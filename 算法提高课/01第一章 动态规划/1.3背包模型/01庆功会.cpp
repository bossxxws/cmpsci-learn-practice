#include<bits/stdc++.h>

using namespace std;

const int N=503;

int w[N];

int v[N];

int s[N];

const int M=6003;

long long  f[N][M];

int main()
{
    int n,m;

    scanf("%d%d",&n,&m);

    //���ر������⣬ÿ����Ʒ�ĸ��������޵�

    for(int i=1;i<=n;i++)
    {

        scanf("%d%d%d",&v[i],&w[i],&s[i]);
    }


    for(int i=1;i<=n;i++)//ö������
    {

        for(int j=0;j<=m;j++)//ö�����
        {

            for(int k=0;k<=s[i];k++)//ö�ٸ���Ʒ���������������ĸ�������С�ڵ�ǰ��Ʒ������
            {
                f[i][j]=max(f[i][j],f[i-1][j]);//��仰û��Ҫ����Ϊf[i][j]��Ȼ����f[i][j-1]

                //��Ϊ������ö��k=0��ʱ��f[i-1][j-k*v[i]]+k*w[i]==f[i-1][j]
                //�������f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+k*w[i])ת��Ϊf[i][j]=max(f[i][j],f[i-1][j])
                //�Ѿ������ˣ�f[i][j]=max(f[i][j],f[i-1][j])���״̬

                if(k*v[i]<=j)f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);

            }
        }
    }


    cout<<f[n][m];
    return 0;
}
