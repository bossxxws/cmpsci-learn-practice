#include<bits/stdc++.h>

using namespace std;

const int N=1010;

int n,m,a,b; 

int g[N][N],minr[N][N],maxr[N][N]; 

int q[N];

typedef long long LL;

const int MOD=998244353;

void getmin(int a[],int b[],int total,int lenth)
{
	int tt=-1,hh=0;
	for(int i=0;i<total;i++)
	{
		//�ж�Ԫ���Ƿ񻬳����� 
		if(hh<=tt && q[hh]<=i-lenth)hh++;
		//�ж���Ԫ�غ;�Ԫ�صĴ�С��ϵȷ�����е���
		while(hh<=tt && a[i]<=a[q[tt]])tt--; 	
		//��� 
		q[++tt]=i;
		//����ֵ�����洢���� ����ͷһ������С�ģ� 
		if(i>=lenth-1)b[i]=a[q[hh]];//i>=k-1��ʾ���������γ�
		
	}
}


void getmax(int a[],int b[],int total,int lenth)
{
	int tt=-1,hh=0;
	for(int i=0;i<total;i++)
	{
		
		if(hh<=tt && q[hh]<=i-lenth)hh++;
		
		while(hh<=tt && a[i]>=a[q[tt]])tt--;
		
		q[++tt]=i;
		
		//��ͷһ�������ģ���ֵ��b 
		if(i>=lenth-1)b[i]=a[q[hh]];
	}
}

int main()
{
	cin>>n>>m>>a>>b;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)scanf("%d",&g[i][j]);
	//for(int i=0;i<n;i++)
		//for(int j=0;j<m;j++)printf("%d",g[i][j]);
	//Ԥ�������ÿһ���л������ڵ���ֵ 
	for(int i=0;i<n;i++)
	{
		getmin(g[i],minr[i],m,b);
		getmax(g[i],maxr[i],m,b);
	}
	
	 
	int res=0;
	
	int A[N],B[N],C[N];
	
	for(int i=b-1;i<m;i++)//�̶��������� 
	{
		for(int j=0;j<n;j++)A[j]=maxr[j][i];//ÿ�У���ÿ������������ȡ����
		getmax(A,B,n,a);//�浽B�� 
		for(int j=0;j<n;j++)A[j]=minr[j][i];//ÿ�У���ÿ��������С����ȡ���� 
		getmin(A,C,n,a);//�浽C�� 
		for(int j=a-1;j<n;j++)	
		{
			res=(res+(LL)B[j]*C[j])%MOD;
		}
	}
	cout<<res;
	return 0;
}
