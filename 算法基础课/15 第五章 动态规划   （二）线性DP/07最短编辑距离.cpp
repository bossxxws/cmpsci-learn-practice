#include<bits/stdc++.h>

using namespace std;

const int N = 1e3+10;

int n,m;

char a[N],b[N];

int f[N][N];//��a��i���䵽b��j������Ҫ�༭�Ĵ��� 
/*
10
AGTCTGACGC
11
AGTAAGTAGGC

4
*/
int main()
{

	scanf("%d%s%d%s",&n,a+1,&m,b+1);
	
	for(int i=0;i<=n;i++)f[i][0]=i;//ɾ
	for(int i=0;i<=m;i++)f[0][i]=i;//��

    for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{

			//�޷�������״̬ȡ��Сֵ
			//�ĵ�ʱ��Ҫ���У������βһ���Ͳ���Ҫ������
			//��һ�����������+1 
			f[i][j]=min(f[i-1][j]+1,f[i][j-1]+1);//����ɾ 
			
			if(a[i]==b[j])f[i][j]=min(f[i][j],f[i-1][j-1]);
			else f[i][j]=min(f[i][j],f[i-1][j-1]+1);//�� 
			
		}
		 
	cout<<f[n][m];
	
	return 0;	
} 
