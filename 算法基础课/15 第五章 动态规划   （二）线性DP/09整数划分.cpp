#include<bits/stdc++.h>

using namespace std;

const int N=1010;

const int MOD=1e9+7;

int f[N][N];//���������� 

int a[N][N];

int n;
//��1~i��ѡ���֣��ܺ�Ϊj��ѡ�������� 
int main()
{
	cin>>n;
	
	//�ܺ�Ϊ0��ʱ�򷽰���Ϊ1
	
	for(int i=0;i<=n;i++)f[i][0]=1; 
	
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n;j++)
		{
			f[i][j]=f[i-1][j]%MOD;
			
			if(j>=i)f[i][j]=(f[i-1][j]+f[i][j-i])%MOD;//f[i-1][j]��ʾ��ѡi�������Ϊi�ķ���
			//f[i][j-1]��ʾѡi�������Ϊj-i�ķ�����ʵ���������һ��ѡi��j-i����i����j�� 
			//Ҳ����f[i][j-1]��ʾѡi�������Ϊi�ĸ�����f[i][j]������f[i][j-1]����״̬�� 
		}	
	
	cout<<f[n][n];
	
	return 0;
} 
