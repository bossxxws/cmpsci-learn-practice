#include<bits/stdc++.h>

using namespace std;

const int N=20,M=1<<20;

int n;

int w[N][N];

int f[M][N];

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&w[i][j]);
		}
	}
	//״̬ѹ��dp 
	memset(f,0x3f,sizeof f);
	//��ʼΪ0
	f[1][0]=0;//i==1��ʾ��һ�����Ѿ����ˣ�j==0��ʾĿǰ�ڵ�һ���� 
	//��0000.����1��ʼ 
	for(int i=1;i<1<<n;i++)
	{
		//�����0��ʼ 
		for(int j=0;j<n;j++)
		{
			//ֻ��i����j����㣬���ܴ�i���״̬ת�Ƶ��յ�Ϊj��״̬ 
			if(i>>j&1)
			{
				//f[i][k]---k-j
				for(int k=0;k<n;k++)
				{
					if((i-(1<<j))>>k&1)
					{
						//(�ò�����j���״̬��ת��)
						f[i][j]=min(f[i][j],f[i-(1<<j)][k]+w[k][j]);
					}
				}
			}
		}
	}
	
	int res=1<<31-1;
	
	//for(int i=1;i<n;i++)
	//{
	//	res=min(res,f[(1<<n)-1][i]);
	//}
	
	//cout<<res<<endl;
	
	//�������յ���n-1������˵ֱ��ѡ�յ���n-1����� 
	cout<<f[(1<<n)-1][n-1];
	return 0;
}
