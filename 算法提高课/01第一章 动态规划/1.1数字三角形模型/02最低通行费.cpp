#include<bits/stdc++.h>

using namespace std;

//״̬��ʾ��f[i][j]����ʾ�ߵ�i��j����ͷ���

const int N=103;

int a[N][N];

int f[N][N];

int main()
{
	int n;
	
	cin >>n;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
		
	memset(f,0x3f,sizeof f);
	//��2n-1��ʱ���ȥ���ǾͶ�һ��ά�ȱ�ʾʱ��
	
	//�ȳ�ʼ����һ����Ҫ�ģ����Ա����ʼ�� 
	f[0][0]=0;
	f[0][1]=0;
	f[1][0]=0;

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			f[i][j] = min({f[i][j], f[i][j - 1] + a[i][j], f[i - 1][j] + a[i][j]});
		}
	
	cout<<f[n][n];
	
	return 0;
}
