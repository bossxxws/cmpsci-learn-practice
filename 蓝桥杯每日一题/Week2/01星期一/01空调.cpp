#include<bits/stdc++.h>

using namespace std;

const int N=1e5+3;

int n;

int a[N],b[N],c[N];

int main()
{
    cin>>n;

    for(int i=1;i<=n;i++)scanf("%d",&a[i]);

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        a[i]=a[i]-b[i];
    }

    for(int i=n;i>0;i--)a[i]-=a[i-1];
    //ע����Ҫ��������Ϊ�������ʱ��a��i-1���Ѿ��ı�

    //����Ҫ����������Ĳ�ֵ���㣬��������������Ĳ�ֵ�Ĳ���������
    //�ò������ȫ������Ĳ������϶��ǲ��������max����������ͣ�abs��������ͣ���

    int pos=0,neg=0;

    for(int i=1;i<=n;i++)
    {
        if(a[i]>0)pos+=a[i];
        if(a[i]<0)neg-=a[i];//����ֱ��ȡ�෴��ֵ�����ֱ��max�ȴ�С
    }

    cout<<max(pos,neg);

    return 0;
}


