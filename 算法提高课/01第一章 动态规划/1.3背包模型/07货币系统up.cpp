#include<bits/stdc++.h>

using namespace std;

unordered_map<int,string>m;//codeblocks-c++11 ��ϣ������ʹ��

typedef long long LL;

const int N=103;

int w[N];//ÿһ����ֵ����������ţ����Կ�����ȫ��������
//˼·��
//�����������Ĵ���ֵ�Ļ����ܱ�ǰ���С��ֵ�Ļ��Ҵճ�������ô�����ֵ�ǿ���ȥ����
//��ô���ϵ�״̬��+1
//�����n��ȥ״̬���ϱ�ʾ��ֵ�Ϳ�����

//���ϱ�ʾ��
bool f[25002];

int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        for(int i=1;i<=n;i++)
        {
            scanf("%d",&w[i]);
        }
        sort(w+1,w+n+1);
//        for(int i=2;i<=n;i++)
//        {
//            memset(f,0,sizeof f);
//            f[0][0]=1;
//            for(int j=1;j<=i;j++)
//            {
//                for(int k=0;k<=w[i];k++)
//                {
//                    f[j][k]+=f[j-1][k];
//                    if(k>=w[j])
//                    {
//                        f[j][k]+=f[j][k-w[j]];
//                        if(f[j][k]!=0)res++;
//                    }
//                }
//            }
//        }

        int res=0;//��������޹���
        int m=w[n];

        memset(f, 0, sizeof f);
        f[0]=true;
        for(int i=1;i<=n;i++)//ö��ÿһ��������ֵ
        {

            //�ȿ��������ǰ����û�б�ɸ��
            if(f[w[i]])continue;//������״̬֮ǰ�ܱ���ʾ��ֱ�����������
            res++;//û����������������޹���+1
            for(int j=w[i];j<=m;j++)
            {
                f[j]|=f[j-w[i]];//�õ�ǰ����ֵɸ��������ܱ���ʾ��ֵ
            }
        }


        cout<<res<<endl;
    }

    return 0;
}

