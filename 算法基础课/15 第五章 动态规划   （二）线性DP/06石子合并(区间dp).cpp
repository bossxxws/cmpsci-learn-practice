#include<bits/stdc++.h>

using namespace std;

const int N=310;

int a[N]; 

int s[N];

int n;

int f[N][N]; 	 

int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	
	for(int len=2;len<=n;len++)//���䳤��
		for(int i=1;i+len-1<=n;i++)
		{
			int l=i,r=i+len-1;//���Ϊi������Ϊlen 
			f[l][r]=1e9;
			//���䳤��Ϊ1��ʱ����Ҫ�ϲ�������Ϊ0�����Բ���Ҫö��
			//ֱ�Ӵ�2��ʼö�� 
			for(int k=l;k<r;k++)
			{
				f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
			}
		} 
		
	
	cout<<f[1][n];
	return 0;
}
