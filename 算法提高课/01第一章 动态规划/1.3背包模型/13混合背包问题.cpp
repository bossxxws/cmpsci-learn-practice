#include<bits/stdc++.h>

using namespace std;

const int N=100010;

int v[N],w[N],s[N];
int chmodv[N];
int chmodw[N];
int f[N];

//����ȫ����ת��Ϊ���ر�������ȡ�������൱���б������/v����Ʒ��
//-1 01 0 ��ȫ >0 ����

int n,m;//m�Ǳ����ݻ�
int main()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {

        cin>>v[i]>>w[i]>>s[i];
        if(s[i]==-1)s[i]=1;//01����ת��Ϊ���ر���
        else if(s[i]==0)s[i]=m/v[i];//��ȫ����ת��Ϊ���ر���

    }

    //�������Ż�(����д��Ҫ����ѭ�����ڵ�����ѭ��ö��s[i])
    //�������Ż��󣬶����Ʒ��������൱��01��������
    //����ֻ��Ҫ01����������������ѭ����
    int cnt=1;
    for(int i=1;i<=n;i++)
    {
        int k=1;//���������ƴ��
        while(k<=s[i])
        {
            chmodv[cnt]=v[i]*k;
            chmodw[cnt]=w[i]*k;
            s[i]-=k;
            k*=2;
            cnt++;
        }
        if(s[i]>0)
        {
            chmodv[cnt]=s[i]*v[i];
            chmodw[cnt]=s[i]*w[i];
            cnt++;
        }
    }///�������Ż����

//    ����д��
//    for(int i=1;i<=cnt;i++)//��ʱ���Ƕ����Ʒ�����һ��������01����һ��
//    {
//        for(int j=0;j<=m;j++)
//        {
//            f[i][j]=f[i-1][j];
//            if(j>=chmodv[i])f[i][j]=max(f[i][j],f[i-1][j-chmodv[i]]+chmodw[i]);
//        }
//
//    }

//  ��������д��(���Դ�������״̬������Ƕ�ά�洢��״̬������)

    for(int i=1;i<=cnt;i++)
    {
        for(int j=m;j>=chmodv[i];j--)
        {
            f[j]=max(f[j],f[j-chmodv[i]]+chmodw[i]);
        }
    }


    cout<<f[m];

    return 0;
}
