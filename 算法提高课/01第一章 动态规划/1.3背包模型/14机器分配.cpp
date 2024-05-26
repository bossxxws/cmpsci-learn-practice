#include<bits/stdc++.h>

using namespace std;

const int N=12,M=17;

int n,m;//��˾�����ͻ�������

int g[N][M];

int f[N][M];

int path[N];
int cnt;

void dfs(int i,int j)
{
    if(i==0)return ;
    for(int a=0;a<=j;a++)
    {

        if(f[i-1][j-a]+g[i][a]==f[i][j])
        {

            path[cnt++]=a;
            dfs(i-1,j-a);
            return ;
        }
    }

}

int main()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&g[i][j]);//�������ݾ���
        }

    //ÿ����˾���Կ���һ���飬��ÿһ����ѡһ��

    for(int i=1;i<=n;i++)//��ǰi������ѡ
    {
        for(int j=1;j<=m;j++)//ö�����(�ܹ�m̨����)
        {
            for(int k = 0;k <= j;k ++)
            {
                f[i][j]=max(f[i][j],f[i-1][j]);
                f[i][j]=max(f[i][j],f[i-1][j-k]+g[i][k]);
                //g[i][k]���Խ��Ϊ���Ϊk����ֵΪg[i][k]
            }
        }
    }

    cout<<f[n][m]<<endl;

    //find path
    dfs(n,m);

    //��Ϊ�Ǵ�����״̬��ʼfind���������
    //����cnt==0��ʱ��洢�������յ�״̬
    //����pathҪ�������
    for(int i=cnt-1,id=1;i>=0;id++,i--)
            cout<<id<<" "<<path[i]<<endl;
}
