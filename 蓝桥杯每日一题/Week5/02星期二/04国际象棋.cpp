#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 110,M=6,MOD=1e9+7;
int f[N][1<<M][1<<M][21];
int n,m,k;
int get_count(int x)//����x�Ķ������ж��ٸ�1
{
    int res=0;
    while(x)
    {
        res++;
        x-=(x&-x);
    }
    return res;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    f[0][0][0][0]=1;//״̬��ʼ������0��ʱ��״ֻ̬����0��ֻ���Ƿ�0����
    //5��ѭ���Ƚ��ң���ͼ������������ͼд
    for(int i=1;i<=m;i++)
    {
        for(int c=0;c<1<<n;c++)
        {
            for(int a=0;a<1<<n;a++)
            {
                if((c&(a<<2))||(a&(c<<2))) continue;
                for(int b=0;b<1<<n;b++)
                {
                    if(b&(a<<2)||a&(b<<2)) continue;
                    if(b&(c<<1)||c&(b<<1)) continue;
                    int t=get_count(b);
                    for(int j=t;j<=k;j++)
                    f[i][a][b][j]=(f[i][a][b][j]+f[i-1][c][a][j-t])%MOD;//��Ӧ���ϻ��֣�ö��j,f[i-1][c][a][j-t]���ܵ���f[i][a][b][j]
                }
            }
        }
    }
    int res=0;
    for(int a=0;a<1<<n;a++)
    {
        for(int b=0;b<1<<n;b++)
        {
            res=(res+f[m][a][b][k])%MOD;//m,k�̶���a,b����
        }
    }
    printf("%d",res);
    return 0;
}

