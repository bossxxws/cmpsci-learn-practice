#include<bits/stdc++.h>

using namespace std;

int n,m,k;

//��α�ʾ��ǰ״̬�� 
//Ƥ����������;�����ĸ������Ա�ʾ��ǰ��״̬��Ҳ��ɣ� 

const int K=103;

const int N=1003,M=503;

int c[K],h[K];//�շ�������Ҫ�ľ�����������Լ�Ƥ�����ܵ����˺�

int f[K][N][M];//f[k][i][j]��ʾ��׽k�����顢���������Ϊi��Ƥ��������Ϊj����������շ��ľ�����������

int main()
{
	cin>>n>>m>>k;
	
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&c[i],&h[i]);
	}
	//cout<<1; 
	//����Ҳ�Ǹ�01�������⣬ֻ�������ϵ��������շ��ľ�������������ֵ
	//�������������ƣ������������ֵ
	//֮ǰֻ��һ�������Ǿ��Ǳ����ݻ� 
	
	int res=-1,t=1e9;
		
	for(int l=1;l<=k;l++)
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
			{
				f[l][i][j]=f[l-1][i][j];				
				if(i>=c[l] && j>=h[l])f[l][i][j]=max(f[l][i][j],f[l-1][i-c[l]][j-h[l]]+1);
				if(f[l][i][j]>res || (f[l][i][j]==res && j<t))
				{
					res=f[l][i][j];
					t=j;
				}				
			} 

//	for(int l=1;l<=k;l++)
//		for(int i=1;i<=n;i++)
//			for(int j=1;i<=m;j++)
//			{
//				cout<<1;
//
//			}
			
	cout<<res<<" "<<m-t;
	return 0;
}
