//����˵����Ϊ12��01����

//��һ����ά���

//0��������һ��
//1��������һ��

//y>=x

//��������������һ��λ����

//�յ�Ϊ��6��6��
//һ����������6����������6��
//��12��������6������ C 12 6

//�Ⱥ���
//��Գ�һ���ǣ�5��7��
//һ������12����һ�����������岽���������߲�
//���Դ�12��������5���������߲���C 12 5 ||  C 12 7 ��

//����-���Ϸ���·��

//C 12 6  -  C 12 5

//C 2n n  -  C 2n n-1

//��������ת��Ϊ C 2n n / ��n+1��     ��������ⱻ��Ϊ����������


//*******        C 2n n / ��n+1)       *******

#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int mod=1e9+7;//���������

//ȡģ��������������������Ԫ�����÷���С������Ȼֻ������չŷ�����
int qmi(int a,int k,int p)
{
    int res=1;
    while(k)
    {
        if(k&1)res=(LL)res*a%p;
        a=(LL)a*a%p;
        k>>=1;
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    
    int a=2*n;
    int b=n;
    
    int res=1;
    
    int t=qmi(n+1,mod-2,mod);
    
    for(int i=a,j=1;j<=b;i--,j++)res=(LL)res *  i  %mod;//����
    for(int i=b;i>=1;i--)res=(LL)res*  qmi(i,mod-2,mod)  %mod;//��ĸ����Ԫ
    
    res=(LL)res*qmi(n+1,mod-2,mod)%mod;
    
    cout<<res;
    
    return 0;
}
