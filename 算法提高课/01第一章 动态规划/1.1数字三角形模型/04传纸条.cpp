#include<bits/stdc++.h>

using namespace std;

const int N=12;

int a[N][N];

int f[N*2][N][N]; 

int main()
{
	//ֻ�������½�����
	
	int n;
	cin>>n;
	
	int r,c,v;
	
	while(cin>>r>>c>>v && (r || c ||v))
	{
		
		a[r][c]=v;//�к��б�Ŵ�1��ʼ 
		
	} 


	//����·��һ������k����i1�ǵ�һ��·���ĺ����꣬i2�ǵڶ���·���ĺ����� 
	//ͨ��i1��i2��k�����Ƴ����Ե�������
	//�������������
	//1:1���������2�������
	//2:1���������2��������
	//3:1����������2�������
	//4:1����������2�������� 
	for(int k=2;k<=2*n;k++)
		for(int i1=1;i1<=n;i1++)
			for(int i2=1;i2<=n;i2++)
			{
				int j1=k-i1,j2=k-i2;
				
				if(j1>=1 && j2>=1 && j1<=n && j2<=n)
				{
					int t=a[i1][j1];
					if(i1!=i2)t+=a[i2][j2];
					int &x=f[k][i1][i2];
					
					//1
					x=max(x,f[k-1][i1-1][i2-1]+t);
					//2
					x=max(x,f[k-1][i1-1][i2]+t);
					//3
					x=max(x,f[k-1][i1][i2-1]+t);
					//4:����������j1-1  j2-1 
					x=max(x,f[k-1][i1][i2]+t);
					
				}
			}

	
	cout<<f[2*n][n][n];
	
	return 0;
	
}
