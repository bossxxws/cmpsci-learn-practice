#include<bits/stdc++.h>

using namespace std;

const int N=10001;

int a[N];

bool f[N][N];//��ʾǰ��i�����ܲ��ܴճ�j�����

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;//<pression1>?<pression2>?<pression3>
	//1Ϊ����ִ��2��1Ϊ����ִ��3 
}

int main()
{
	int n;
	cin>>n;
	int d;
	//���ǵ����Լ������1�Ļ�������������޷��ճ����� 
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		d=gcd(d,a[i]);//����Щ�������Լ�� 
	}
	
	//�������Ļ�������������������Լ����1�����ǲ��ܴճ�����
	//�������ǣ���a-1����b-1��-1
	
	//�����n�����Ļ��� 
	//���룺����������������ܴճ��������������� ��a-1����b-1��-1
	//�����n�������ǿ϶����Ĳ��ܴճ��������϶��� ��a-1����b-1��-1С
	
	//����ö��װ̨��ʱ�����Ǿ��������������ö��һ�飨����a��b���Ϊ100��
	//���Ǿ�ö�ٵ�10000 
	
	f[0][0]=1;
	
	if(d!=1)
	{
		cout<<"INF"<<endl;
	}
	else
	{
		for(int i=1;i<=n;i++)
			for(int j=0;j<N;j++)
			{
				f[i][j]=f[i-1][j];
				if(a[i]<=j)f[i][j]|=f[i][j-a[i]];
			}
		
		int res=0;
		
		for(int i=0;i<N;i++)
		{
			if(!f[n][i])res++;
		}
		cout<<res<<endl;
	}

	return 0;
} 
