#include<bits/stdc++.h>

using namespace std;

int n;

const int N=1006;

int a[N][N];

int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	
	for(int i=2;i<=2*n;i++)
	{
		if(i%2)//�ܺ�Ϊ�����������ż���У� ���� 
		{
			for(int j=1;j<=i-1;j++)//ö���� 
			{
				if(j<=n && (i-j)<=n)
				{
					cout<<a[j][i-j]<<" ";
				}
			}
		}
		else
		{
			for(int j=i-1;j>=1;j--)
			{
				if(j<=n && (i-j)<=n)
				{
					cout<<a[j][i-j]<<" ";
				}
			}
		} 
	}
	

	
	return 0;
}
