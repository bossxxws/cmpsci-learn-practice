#include<bits/stdc++.h>

using namespace std;

const int N=1010;

int n,m; 

char a[N],b[N];

int f[N][N];
//f[i][j]��ʾa�����±�i��β��b�����±�j��β�������������ĳ��� 
int main()
{
	cin>>n>>m>>a+1>>b+1;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			f[i][j]=max(f[i-1][j],f[i][j-1]);
			if(a[i]==b[j])f[i][j]=max(f[i][j],f[i-1][j-1]+1);	
		}	
	
	cout<<f[n][m];
	return 0;
}
