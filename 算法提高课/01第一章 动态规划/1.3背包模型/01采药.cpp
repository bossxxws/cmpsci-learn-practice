//��������
//01�������� 

#include<bits/stdc++.h>

using namespace std;

const int N=103;

int v[N],w[N];//���v����ֵw 

const int T=1010;//����������ݻ���1000 

int t,m; 

int f[N][T];//ע��ڶ���ά�ȵĴ�С��T 
//f[i][j]��ʾ����ѡ����Ϊi������£������������j�ļ�ֵ�ļ���
//���ԣ�max  
int main()
{
	scanf("%d%d",&t,&m);
	
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&v[i],&w[i]);
		//cout<<v[i]<<" "<<w[i]<<endl; 
	} 
	
	//��ʼ״̬ת�� 
	
	for(int i=1;i<=m;i++)//��ѡһ�ֿ�ʼö�� (�ܹ�m��)
		for(int j=0;j<=t;j++)//���������ܳ���t 
		{
			f[i][j]=f[i-1][j];//��ѡ��i����Ʒ 
			
			if(j>=v[i])f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);//ѡ��i����Ʒ 
		}
	
	cout<<f[m][t]<<endl;
	return 0;
} 
