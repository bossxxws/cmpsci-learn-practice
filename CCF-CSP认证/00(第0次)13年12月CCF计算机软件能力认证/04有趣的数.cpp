#include<bits/stdc++.h>

using namespace std;

const int mod=1e9+7,N=1010;
int n; 


typedef long long LL;
LL C[N][N];
int main()
{
	//����01ѡk���� 
	//��ѡk��01��䣨C n-1 k����n-1����Ϊ��һλ������0����1��������01�����е���������ǣ�k-1�� ��
	//ʣ�µ�23���ͬ�� �У�n-k-1��  ����
	//��� 
	
	//���ΰ�ÿ��k��ȡֵ�����ӣ���2��n-2�� 
	cin>>n;
	
	//Ԥ�������������� 
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(!j)C[i][j]=1;
			else 
			{
				C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
			}
		}
	}
	LL res=0;
	for(int i=2;i<=n-2;i++)
	{
		res=(res+(LL)C[n-1][i]*(i-1)%mod*(n-i-1))%mod;
	}
	
	cout<<res;
	return 0;
} 
