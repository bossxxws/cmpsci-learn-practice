#include<bits/stdc++.h>

using namespace std;

const int N=303;

int a[N];

int n;

int f[N][N];//���н�����i~j�ϲ���һ�ѵļ����������Сֵ 

int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]+=a[i-1];
	}
	//memset(f,0x3f,sizeof f); 
	for(int len=2;len<=n;len++)//��ö�����䳤�� 
		for(int i=1;i+len-1<=n;i++)//��ö����˵㣨�Ҷ˵��Զ������--j�� 
		{
			int j=i+len-1;
			f[i][j]=1e8;//����Ҫ����Сֵ�������ȸ����״̬һ���Ƚϴ��ֵ 
			for(int k=i;k<=j;k++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+a[j]-a[i-1]);	
			}
		}
	
	cout<<f[1][n];//�ϲ�1~n����Ҫ��������������С��ֵ 
	return 0;
} 
