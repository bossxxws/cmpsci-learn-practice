#include<bits/stdc++.h>

using namespace std;

const int N=1003; 

int n,m; 

int f[N];//f[i][j]��ʾ��ǰi����Ʒѡ��������������j��ѡ�� 

int v[N],w[N]; 

int main()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)scanf("%d%d",&v[i],&w[i]);
	
	for(int i=1;i<=n;i++)
		for(int j=m;j>=v[i];j--)//��Ϊ�õ�����һ��״̬������Ҫ������ 
		{
			if(j>=v[i])f[j]=max(f[j],f[j-v[i]]+w[i]);
		}
	
	cout<<f[m];
	
	return 0;
} 
