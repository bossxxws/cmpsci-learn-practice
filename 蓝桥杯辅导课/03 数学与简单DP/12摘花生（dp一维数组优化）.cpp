#include<bits/stdc++.h>

using namespace std;

const int N=1003;

int t;
int n,m; 

int a[N][N];
int f[N];

//�ɵݹ���Կ�����״̬����������ά�ȱ�ʾ��x �� y 

//��ֹ״̬Ϊi=n;j=m 

//Ŀ��ֵ����dfs�ĳ�ʼֵa[1][1] 

//Ҳ���Խ�ֹ״̬i=1 j=1
//��ôĿ��ֵ����i=n j=m  
int main()
{
	cin>>t;
	
	while(t--)
	{
		cin>>n>>m;
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&a[i][j]);
			}
		for(int i=1;i<=n;i++) 
			for(int j=1;j<=m;j++)
			{
				f[j]=max(f[j],f[j-1])+a[i][j];
			}
		cout<<f[m]<<endl;
		memset(f,0,sizeof f);
	}
	return 0;
}
