#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N=10003;

int kind[28];

LL f[N][N];//ȡǰi�֣�����������ֵΪj��ȡ������ 

int main()
{
	int v,n;
	cin>>v>>n;
	for(int i=1;i<=v;i++)
	{
		scanf("%d",&kind[i]);
	}
	f[0][0]=1;
	for(int i=1;i<=v;i++)
		for(int j=0;j<=n;j++)
		{
			f[i][j]+=f[i-1][j];
			if(j>=kind[i])f[i][j]+=f[i][j-kind[i]];//��Ϊ��+�������в�ȡ����� 
		}
	//cout<<f[2][0];
	cout<<f[v][n];
	return 0;
 } 
