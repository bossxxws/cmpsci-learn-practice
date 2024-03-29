#include<iostream>

using namespace std;

typedef long long LL;

const int N=1e6+10;

int primes[N],cnt;

int phi[N];//�洢ŷ������ 

bool st[N];


//����ɸ�� 
LL get_eulers(int n)
{
	phi[1]=1;// �Ӷ��������1-1�к�1���ʵ���ֻ��1�Լ� 
    for(int i=2;i<=n;i++)
    {
        if(!st[i])
        {
        	primes[cnt++]=i;
        	//�����������������������ŷ�������� 
			//such as p��p����p-1�����ʵ�����1-��p-1���� 
			//����p��ŷ����������p-1 
        	phi[i]=i-1; 
        }
        for(int j=0;primes[j]<=n/i;j++)
        {
        	st[primes[j]*i]=true;
        	if(i%primes[j]==0)
        	{
        		//��ʱpj*i��ŷ��������ʲô��
				//��ʱpj��i��һ��������
				//����pj*i�����������Ӿ���i������������
				//��ʱ�����Ƴ�����pj*i����ŷ����������pj*��i��ŷ�������� 
				phi[primes[j]*i]=primes[j]*phi[i];
				break; 
        	}
        	//i%primes[j]!=0ʱ
			//pj��i*pj����С������
			//�ܵó���pj*i����ŷ��������i��ŷ������*��pj-1�� 
			phi[primes[j]*i]=phi[i]*(primes[j]-1);
        }
    }
    LL res=0;
    for(int i=1;i<=n;i++)res+=phi[i];
    return res;
}

int main()
{
    int n;
    cin>>n;
    
    cout<<get_eulers(n);
}
